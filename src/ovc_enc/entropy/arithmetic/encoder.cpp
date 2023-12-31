#include "ovc_enc/entropy/arithmetic/encoder.h"

arithmetic_encoder::arithmetic_encoder()
	: low(0)
	// 16 bit precision
	, high((uint32_t(0x1) << 16) - 1)
	, mid(high >> 1)
	, underflow_count(0)
{
	history[0] = history[1] = 1;

	entropy_precision = 16;
	entropy_precision_max = (uint32_t(0x1) << entropy_precision) - 1;
	entropy_half_range = (entropy_precision_max >> 1);
	entropy_qtr_range = (entropy_half_range >> 1);
	entropy_3qtr_range = 3 * entropy_qtr_range;
	entropy_msb_mask = (uint64_t(0x1) << (entropy_precision - 1));
}

void arithmetic_encoder::encode(const uint8_t* in_bytes, size_t in_size)
{
	for (size_t i = 0; i < in_size; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			encode_internal((in_bytes[i] >> j) & 0x1);
		}
	}
}

void arithmetic_encoder::flush(uint8_t** out_bytes, size_t* out_size)
{
	underflow_count++;

	uint8_t val = (low < ((uint32_t(0x1) << 16) - 1) >> 2) ? 0 : 1;
	bitstream->write_bit(val);
	flush_inverse_bits(val);

	*out_bytes = new uint8_t[bitstream->occupancy()];
	memcpy(*out_bytes, bitstream->data(), bitstream->occupancy());
	*out_size = bitstream->occupancy();

	clear();
}

void arithmetic_encoder::clear()
{
	low = 0;
	underflow_count = 0;

	history[0] = history[1] = 1;
	high = (uint32_t(0x1) << 16) - 1;
	mid = high >> 1;

	delete bitstream;
	bitstream = new ovc_bitstream();
}

void arithmetic_encoder::update()
{
	uint32_t range = high - low;
	uint64_t mid_range = range * history[0] / (history[0] + history[1]);

	mid = low + (uint32_t)mid_range;
}

void arithmetic_encoder::flush_inverse_bits(uint8_t in_symbol)
{
	in_symbol = !in_symbol;
	for (uint32_t i = 0; i < underflow_count; i++)
	{
		bitstream->write_bit(in_symbol);
	}

	underflow_count = 0;
}

void arithmetic_encoder::encode_internal(uint8_t in_symbol)
{
	update();

	// Update bounds based on new information
	if (in_symbol)
	{
		low = mid + 1;
	}
	else
	{
		high = mid;
	}

	history[in_symbol]++;

	while (true)
	{
		if ((high & entropy_msb_mask) == (low & entropy_msb_mask))
		{
			// Common prefix. Write it out to the stream so we can still use the full
			// 16 bits for storing low and high
			uint8_t msb = (uint8_t)((high & entropy_msb_mask) >> 15);
			low -= entropy_half_range * msb + msb;
			high -= entropy_half_range * msb + msb;

			bitstream->write_bit(msb);
			flush_inverse_bits(msb);
		}
		else if (high <= entropy_3qtr_range && low > entropy_qtr_range)
		{
			// Underflow
			// Caused by low and high approaching the same value, but from different sides
			// eg 0.10' ~ 0.01'
			high -= entropy_qtr_range + 1;
			low -= entropy_qtr_range + 1;
			underflow_count += 1;
		}
		else
		{
			break;
		}

		high = ((high << 0x1) & entropy_precision_max) | 0x1;
		low = ((low << 0x1) & entropy_precision_max) | 0x0;
	}
}
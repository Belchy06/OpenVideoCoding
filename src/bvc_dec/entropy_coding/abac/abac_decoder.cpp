#include <cstring>
#include <iostream>
#include "abac_decoder.h"

abac_decoder::abac_decoder()
	: low(0)
	// 16 bit precision
	, high((uint32_t(0x1) << 16) - 1)
	, mid(high >> 1)
	, encoded(0)
{
	history[0] = history[1] = 1;
	stream = new bitstream();

	entropy_precision = 16;
	entropy_precision_max = (uint32_t(0x1) << entropy_precision) - 1;
	entropy_half_range = (entropy_precision_max >> 1);
	entropy_qtr_range = (entropy_half_range >> 1);
	entropy_3qtr_range = 3 * entropy_qtr_range;
}

void abac_decoder::decode(uint8_t* in_bytes, size_t in_size, size_t in_num_symbols)
{
	for (size_t i = 0; i < in_size; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			// size_t	bitIdx = i * 8 + j;
			uint8_t bit = (in_bytes[i] >> j) & 0x1;

			bits.push(bit);
		}
	}

	for (size_t i = 0; i < entropy_precision; i++)
	{
		encoded <<= 0x1;
		encoded |= (uint32_t)bits.front();
		bits.pop();
	}

	for (size_t i = 0; i < in_num_symbols; i++)
	{
		decode_internal();
	}
}

void abac_decoder::decode_internal()
{
	update();

	if (encoded >= low && encoded <= mid)
	{
		high = mid;
		history[0]++;
		stream->write_bit(0);
	}
	else if (encoded > mid && encoded <= high)
	{
		low = mid + 1;
		history[1]++;
		stream->write_bit(1);
	}

	while (true)
	{
		if (high <= entropy_half_range)
		{
			/* If our high value is less than half we do nothing (but
			   prevent the loop from exiting). */
		}
		else if (low > entropy_half_range)
		{
			high -= entropy_half_range + 1;
			low -= entropy_half_range + 1;
			encoded -= entropy_half_range + 1;
		}
		else if (high <= entropy_3qtr_range && low > entropy_qtr_range)
		{
			/* E3 scaling violation. */
			high -= entropy_qtr_range + 1;
			low -= entropy_qtr_range + 1;
			encoded -= entropy_qtr_range + 1;
		}
		else
		{
			break;
		}

		uint8_t bit = 0;
		if (!bits.empty())
		{
			bit = bits.front();
			bits.pop();
		}
		high = ((high << 0x1) & entropy_precision_max) | 0x1;
		low = ((low << 0x1) & entropy_precision_max) | 0x0;
		encoded = ((encoded << 0x1) & entropy_precision_max) | bit;
	}
}

void abac_decoder::flush(uint8_t** out_bits, size_t* out_size)
{
	*out_bits = new uint8_t[stream->occupancy()];
	memcpy(*out_bits, stream->data(), stream->occupancy());
	*out_size = stream->occupancy();

	clear();
}

void abac_decoder::clear()
{
	low = 0;

	history[0] = history[1] = 1;
	high = (uint32_t(0x1) << 16) - 1;
	mid = high >> 1;
}

void abac_decoder::update()
{
	uint32_t range = high - low;
	uint64_t mid_range = range * history[0] / (history[0] + history[1]);

	mid = low + (uint32_t)mid_range;
}
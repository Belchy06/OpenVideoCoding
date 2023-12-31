#include "ovc_dec/entropy/skip/decoder.h"

void skip_entropy_decoder::decode(uint8_t* in_bytes, size_t in_size, size_t in_num_symbols)
{
	for (size_t i = 0; i < in_size; i++)
	{
		bitstream->write_byte(in_bytes[i]);
	}
}

void skip_entropy_decoder::flush(uint8_t** out_bytes, size_t* out_size)
{
	*out_bytes = new uint8_t[bitstream->occupancy()];
	memcpy(*out_bytes, bitstream->data(), bitstream->occupancy());
	*out_size = bitstream->occupancy();

	delete bitstream;
	bitstream = new ovc_bitstream();
}
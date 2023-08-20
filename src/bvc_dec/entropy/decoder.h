#pragma once

#include <queue>
#include <stdint.h>

#include "bvc_common/bitstream/bitstream.h"

class bvc_entropy_decoder
{
public:
	bvc_entropy_decoder()
		: bitstream(new bvc_bitstream()) {}

	// Each implementation is responisble for handling decoding
	virtual void decode(uint8_t* in_bytes, size_t in_size, size_t in_num_symbols) = 0;

	// Each implementation is responisble for the retrieval of decoded data
	virtual void flush(uint8_t** out_bits, size_t* out_size) = 0;

protected:
	bvc_bitstream* bitstream;

	std::queue<uint8_t> bits;
};
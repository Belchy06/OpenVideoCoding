#pragma once

#include <memory>

#include "bvc_dec/entropy/decoder.h"
#include "bvc_common/entropy/entropy.h"

class bvc_entropy_decoder_factory
{
public:
	static std::shared_ptr<bvc_entropy_decoder> create_entropy_decoder(bvc_entropy_coder in_coder);
};
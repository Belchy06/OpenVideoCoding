#pragma once

#include <memory>

#include "entropy_decoder.h"
#include "bvc_common/entropy.h"

class bvc_entropy_decoder_factory
{
public:
	static std::shared_ptr<bvc_entropy_decoder> create_entropy_coder(bvc_entropy in_coder);
};
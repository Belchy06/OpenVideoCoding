#include "entropy_decoder_factory.h"
#include "abac/abac_decoder.h"

std::shared_ptr<bvc_entropy_decoder> bvc_entropy_decoder_factory::create_entropy_decoder(bvc_entropy in_coder)
{
	switch (in_coder)
	{
		case bvc_entropy::BVC_ENTROPY_CODER_ABAC:
			return std::make_shared<abac_decoder>();
		case bvc_entropy::BVC_ENTROPY_CODER_NONE:
			return nullptr;
		default:
			return nullptr;
	}
}
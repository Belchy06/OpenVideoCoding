#include "bvc_dec/wavelet/biorthogonal/recomposer.h"
#include "bvc_dec/wavelet/coiflets/recomposer.h"
#include "bvc_dec/wavelet/haar/recomposer.h"
#include "bvc_dec/wavelet/recomposer_factory.h"

std::shared_ptr<bvc_wavelet_recomposer> bvc_wavelet_recomposer_factory::create_wavelet_recomposer(bvc_wavelet_family in_wavelet_transform, bvc_wavelet_config in_config)
{
	switch (in_wavelet_transform)
	{
		case BVC_WAVELET_FAMILY_HAAR:
			return std::make_shared<haar_recomposer>(in_config);
		case BVC_WAVELET_FAMILY_BIORTHOGONAL:
			return std::make_shared<biorthogonal_recomposer>(in_config);
		case BVC_WAVELET_FAMILY_COIFLETS:
			return std::make_shared<coiflets_recomposer>(in_config);
		default:
			return nullptr;
	}
}
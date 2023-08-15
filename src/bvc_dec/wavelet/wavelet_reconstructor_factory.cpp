#include "biorthogonal/biorthogonal_reconstructor.h"
#include "coiflets/coiflets_reconstructor.h"
#include "haar/haar_reconstructor.h"
#include "wavelet_reconstructor_factory.h"

std::shared_ptr<bvc_wavelet_reconstructor> bvc_wavelet_reconstructor_factory::create_wavelet_reconstructor(bvc_wavelet in_wavelet, bvc_wavelet_config in_config)
{
	switch (in_wavelet)
	{
		case bvc_wavelet::BVC_WAVELET_HAAR:
			return std::make_shared<haar_reconstructor>(in_config);
		case bvc_wavelet::BVC_WAVELET_BIORTHOGONAL:
			return std::make_shared<biorthogonal_reconstructor>(in_config);
		case bvc_wavelet::BVC_WAVELET_COIFLETS:
			return std::make_shared<coiflets_reconstructor>(in_config);
		case bvc_wavelet::BVC_WAVELET_NONE:
			return nullptr;
		default:
			return nullptr;
	}
}
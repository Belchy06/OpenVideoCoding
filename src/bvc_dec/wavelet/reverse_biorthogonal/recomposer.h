#pragma once

#include "bvc_common/wavelet/wavelet_config.h"
#include "bvc_dec/wavelet/recomposer.h"

class reverse_biorthogonal_recomposer : public bvc_wavelet_recomposer
{
public:
	reverse_biorthogonal_recomposer(bvc_wavelet_config in_config);

	virtual matrix<double> recompose(bvc_wavelet_decomposition_2d<double>& in_decomposition, const matrix_size& in_size_rec) const override;
};
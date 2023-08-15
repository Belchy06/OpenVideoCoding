#pragma once

#include "bvc_common/wavelet/wavelet.h"

class bvc_wavelet_reconstructor
{
public:
	virtual matrix<double> reconstruct(const bvc_wavelet_decomposition_2d<double>& in_decomposition, const matrix_size& in_size_rec) const = 0;

protected:
	wavelet<double>* wave;
};
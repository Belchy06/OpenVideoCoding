#pragma once

#include <stdint.h>
#include <string>

typedef enum : uint8_t
{
	OVC_WAVELET_REVERSE_BIORTHOGONAL_1p1,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_1p3,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_1p5,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_2p2,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_2p4,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_2p6,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_2p8,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_3p1,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_3p3,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_3p5,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_3p7,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_3p9,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_4p4,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_5p5,
	OVC_WAVELET_REVERSE_BIORTHOGONAL_6p8
} ovc_wavelet_reverse_biorthogonal_config;

inline std::string reverse_biorthogonal_config_to_string(ovc_wavelet_reverse_biorthogonal_config in_reverse_biorthogonal_config)
{
	switch (in_reverse_biorthogonal_config)
	{
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_1p1:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_1p1";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_1p3:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_1p3";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_1p5:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_1p5";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_2p2:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_2p2";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_2p4:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_2p4";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_2p6:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_2p6";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_2p8:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_2p8";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_3p1:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_3p1";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_3p3:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_3p3";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_3p5:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_3p5";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_3p7:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_3p7";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_3p9:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_3p9";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_4p4:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_4p4";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_5p5:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_5p5";
		case OVC_WAVELET_REVERSE_BIORTHOGONAL_6p8:
			return "OVC_WAVELET_REVERSE_BIORTHOGONAL_6p8";
		default:
			return "";
	}
}
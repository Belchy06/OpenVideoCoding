#pragma once

#include <stdint.h>
#include <string>

typedef enum : uint8_t
{
	OVC_WAVELET_DAUBECHIES_1,
	OVC_WAVELET_DAUBECHIES_2,
	OVC_WAVELET_DAUBECHIES_3,
	OVC_WAVELET_DAUBECHIES_4,
	OVC_WAVELET_DAUBECHIES_5,
	OVC_WAVELET_DAUBECHIES_6,
	OVC_WAVELET_DAUBECHIES_7,
	OVC_WAVELET_DAUBECHIES_8,
	OVC_WAVELET_DAUBECHIES_9,
	OVC_WAVELET_DAUBECHIES_10,
	OVC_WAVELET_DAUBECHIES_11,
	OVC_WAVELET_DAUBECHIES_12,
	OVC_WAVELET_DAUBECHIES_13,
	OVC_WAVELET_DAUBECHIES_14,
	OVC_WAVELET_DAUBECHIES_15,
	OVC_WAVELET_DAUBECHIES_16,
	OVC_WAVELET_DAUBECHIES_17,
	OVC_WAVELET_DAUBECHIES_18,
	OVC_WAVELET_DAUBECHIES_19,
	OVC_WAVELET_DAUBECHIES_20
} ovc_wavelet_daubechies_config;

inline std::string daubechies_config_to_string(ovc_wavelet_daubechies_config in_daubechies_config)
{
	switch (in_daubechies_config)
	{
		case OVC_WAVELET_DAUBECHIES_1:
			return "OVC_WAVELET_DAUBECHIES_1";
		case OVC_WAVELET_DAUBECHIES_2:
			return "OVC_WAVELET_DAUBECHIES_2";
		case OVC_WAVELET_DAUBECHIES_3:
			return "OVC_WAVELET_DAUBECHIES_3";
		case OVC_WAVELET_DAUBECHIES_4:
			return "OVC_WAVELET_DAUBECHIES_4";
		case OVC_WAVELET_DAUBECHIES_5:
			return "OVC_WAVELET_DAUBECHIES_5";
		case OVC_WAVELET_DAUBECHIES_6:
			return "OVC_WAVELET_DAUBECHIES_6";
		case OVC_WAVELET_DAUBECHIES_7:
			return "OVC_WAVELET_DAUBECHIES_7";
		case OVC_WAVELET_DAUBECHIES_8:
			return "OVC_WAVELET_DAUBECHIES_8";
		case OVC_WAVELET_DAUBECHIES_9:
			return "OVC_WAVELET_DAUBECHIES_9";
		case OVC_WAVELET_DAUBECHIES_10:
			return "OVC_WAVELET_DAUBECHIES_10";
		case OVC_WAVELET_DAUBECHIES_11:
			return "OVC_WAVELET_DAUBECHIES_11";
		case OVC_WAVELET_DAUBECHIES_12:
			return "OVC_WAVELET_DAUBECHIES_12";
		case OVC_WAVELET_DAUBECHIES_13:
			return "OVC_WAVELET_DAUBECHIES_13";
		case OVC_WAVELET_DAUBECHIES_14:
			return "OVC_WAVELET_DAUBECHIES_14";
		case OVC_WAVELET_DAUBECHIES_15:
			return "OVC_WAVELET_DAUBECHIES_15";
		case OVC_WAVELET_DAUBECHIES_16:
			return "OVC_WAVELET_DAUBECHIES_16";
		case OVC_WAVELET_DAUBECHIES_17:
			return "OVC_WAVELET_DAUBECHIES_17";
		case OVC_WAVELET_DAUBECHIES_18:
			return "OVC_WAVELET_DAUBECHIES_18";
		case OVC_WAVELET_DAUBECHIES_19:
			return "OVC_WAVELET_DAUBECHIES_19";
		case OVC_WAVELET_DAUBECHIES_20:
			return "OVC_WAVELET_DAUBECHIES_20";
		default:
			return "";
	}
}
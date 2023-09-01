#pragma once

#include <stdint.h>
#include <string>

namespace ovc
{
	typedef enum : uint8_t
	{
		WAVELET_DAUBECHIES_1,
		WAVELET_DAUBECHIES_2,
		WAVELET_DAUBECHIES_3,
		WAVELET_DAUBECHIES_4,
		WAVELET_DAUBECHIES_5,
		WAVELET_DAUBECHIES_6,
		WAVELET_DAUBECHIES_7,
		WAVELET_DAUBECHIES_8,
		WAVELET_DAUBECHIES_9,
		WAVELET_DAUBECHIES_10,
		WAVELET_DAUBECHIES_11,
		WAVELET_DAUBECHIES_12,
		WAVELET_DAUBECHIES_13,
		WAVELET_DAUBECHIES_14,
		WAVELET_DAUBECHIES_15,
		WAVELET_DAUBECHIES_16,
		WAVELET_DAUBECHIES_17,
		WAVELET_DAUBECHIES_18,
		WAVELET_DAUBECHIES_19,
		WAVELET_DAUBECHIES_20
	} wavelet_daubechies_config;

	inline std::string daubechies_config_to_string(wavelet_daubechies_config in_daubechies_config)
	{
		switch (in_daubechies_config)
		{
			case WAVELET_DAUBECHIES_1:
				return "WAVELET_DAUBECHIES_1";
			case WAVELET_DAUBECHIES_2:
				return "WAVELET_DAUBECHIES_2";
			case WAVELET_DAUBECHIES_3:
				return "WAVELET_DAUBECHIES_3";
			case WAVELET_DAUBECHIES_4:
				return "WAVELET_DAUBECHIES_4";
			case WAVELET_DAUBECHIES_5:
				return "WAVELET_DAUBECHIES_5";
			case WAVELET_DAUBECHIES_6:
				return "WAVELET_DAUBECHIES_6";
			case WAVELET_DAUBECHIES_7:
				return "WAVELET_DAUBECHIES_7";
			case WAVELET_DAUBECHIES_8:
				return "WAVELET_DAUBECHIES_8";
			case WAVELET_DAUBECHIES_9:
				return "WAVELET_DAUBECHIES_9";
			case WAVELET_DAUBECHIES_10:
				return "WAVELET_DAUBECHIES_10";
			case WAVELET_DAUBECHIES_11:
				return "WAVELET_DAUBECHIES_11";
			case WAVELET_DAUBECHIES_12:
				return "WAVELET_DAUBECHIES_12";
			case WAVELET_DAUBECHIES_13:
				return "WAVELET_DAUBECHIES_13";
			case WAVELET_DAUBECHIES_14:
				return "WAVELET_DAUBECHIES_14";
			case WAVELET_DAUBECHIES_15:
				return "WAVELET_DAUBECHIES_15";
			case WAVELET_DAUBECHIES_16:
				return "WAVELET_DAUBECHIES_16";
			case WAVELET_DAUBECHIES_17:
				return "WAVELET_DAUBECHIES_17";
			case WAVELET_DAUBECHIES_18:
				return "WAVELET_DAUBECHIES_18";
			case WAVELET_DAUBECHIES_19:
				return "WAVELET_DAUBECHIES_19";
			case WAVELET_DAUBECHIES_20:
				return "WAVELET_DAUBECHIES_20";
			default:
				return "";
		}
	}
} // namespace ovc
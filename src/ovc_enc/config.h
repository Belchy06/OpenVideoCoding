#pragma once

#include <stdint.h>

#include "ovc_common/format.h"
#include "ovc_common/verbosity.h"
#include "ovc_common/entropy/entropy.h"
#include "ovc_common/interleave/interleave.h"
#include "ovc_common/partition/partition.h"
#include "ovc_common/spiht/spiht.h"
#include "ovc_common/wavelet/wavelet.h"
#include "ovc_enc/preset.h"

class ovc_enc_config
{
public:
	size_t			  width;
	size_t			  height;
	ovc_chroma_format format;
	float			  framerate;
	float			  bits_per_pixel;
	uint16_t		  seed;

	int num_parts_exp = -1;
	int num_levels = -1;

	ovc_enc_preset	   preset;
	ovc_wavelet_family wavelet_family;
	ovc_wavelet_config wavelet_config;
	ovc_partition	   partition_type;
	ovc_spiht		   spiht;
	ovc_entropy_coder  entropy_coder;
	ovc_interleave	   interleaver;

	bool repeat_vps;
	bool multithreading;

	ovc_verbosity log_verbosity;
};
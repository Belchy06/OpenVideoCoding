#include <cmath>

#include "ovc_enc/spiht/spiht/encoder.h"

spiht_encoder::spiht_encoder()
{
	clear();
}

void spiht_encoder::encode(matrix<double> in_matrix, ovc_spiht_config in_config)
{
	size_t width = in_matrix.get_num_columns();
	size_t height = in_matrix.get_num_rows();
	// TODO (belchy06): This should update based on the plane
	size_t bit_allocation = (size_t)ceil(width * height * in_config.bpp);

	int max = INT_MIN;
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			double pixel = in_matrix(y, x);
			if (std::abs(pixel) > max)
			{
				max = (int)std::abs(pixel);
			}
		}
	}

	uint16_t step = (uint16_t)floor(log((float)max) / log(2.f));
	output_step = step;
	for (size_t y = 0; y <= height / (1 << in_config.num_levels); y++)
	{
		for (size_t x = 0; x <= width / (1 << in_config.num_levels); x++)
		{
			lip.push_back(ovc_spiht_pixel(x, y));
			if ((x % 2 != 0) || (y % 2 != 0))
			{
				lis.push_back(ovc_spiht_set(x, y, OVC_SPIHT_TYPE_A));
			}
		}
	}

	size_t bit_cnt = 0;
	while (step >= 0)
	{
		// sorting pass
		// process LIP
		for (size_t i = 0; i < lip.size(); i++)
		{
			bool significant = is_significant_pixel(in_matrix, lip[i].x, lip[i].y, step);
			bitstream->write_bit(uint8_t(significant));
			if (++bit_cnt > bit_allocation)
			{
				return;
			}
			if (significant)
			{
				lsp.push_back(ovc_spiht_pixel(lip[i].x, lip[i].y));
				bitstream->write_bit(((int64_t)in_matrix(lip[i].y, lip[i].x)) > 0 ? 0 : 1);
				if (++bit_cnt > bit_allocation)
				{
					return;
				}
				lip.erase(lip.begin() + i);
				i--;
			}
		}
		// process LIS
		for (size_t i = 0; i < lis.size(); i++)
		{
			if (lis[i].type == OVC_SPIHT_TYPE_A)
			{
				bool significant = is_significant_set_A(in_matrix, in_config.num_levels, lis[i].x, lis[i].y, step);
				bitstream->write_bit((uint8_t)significant);
				if (++bit_cnt > bit_allocation)
				{
					return;
				}
				if (significant)
				{
					int64_t sx, sy;
					get_successor(in_matrix, in_config.num_levels, lis[i].x, lis[i].y, &sx, &sy);
					// process the four offsprings
					significant = is_significant_pixel(in_matrix, sx, sy, step);
					bitstream->write_bit((uint8_t)significant);
					if (++bit_cnt > bit_allocation)
					{
						return;
					}

					if (significant)
					{
						lsp.push_back(ovc_spiht_pixel(sx, sy));
						bitstream->write_bit(((int64_t)in_matrix(sy, sx)) > 0 ? 0 : 1);
						if (++bit_cnt > bit_allocation)
						{
							return;
						}
					}
					else
					{
						lip.push_back(ovc_spiht_pixel(sx, sy));
					}
					significant = is_significant_pixel(in_matrix, sx + 1, sy, step);
					bitstream->write_bit((uint8_t)significant);
					if (++bit_cnt > bit_allocation)
					{
						return;
					}
					if (significant)
					{
						lsp.push_back(ovc_spiht_pixel(sx + 1, sy));
						bitstream->write_bit(((int64_t)in_matrix(sy, sx + 1)) > 0 ? 0 : 1);
						if (++bit_cnt > bit_allocation)
						{
							return;
						}
					}
					else
					{
						lip.push_back(ovc_spiht_pixel(sx + 1, sy));
					}
					significant = is_significant_pixel(in_matrix, sx, sy + 1, step);
					bitstream->write_bit((uint8_t)significant);
					if (++bit_cnt > bit_allocation)
					{
						return;
					}
					if (significant)
					{
						lsp.push_back(ovc_spiht_pixel(sx, sy + 1));
						bitstream->write_bit(((int64_t)in_matrix(sy + 1, sx)) > 0 ? 0 : 1);
						if (++bit_cnt > bit_allocation)
						{
							return;
						}
					}
					else
					{
						lip.push_back(ovc_spiht_pixel(sx, sy + 1));
					}
					significant = is_significant_pixel(in_matrix, sx + 1, sy + 1, step);
					bitstream->write_bit((uint8_t)significant);
					if (++bit_cnt > bit_allocation)
					{
						return;
					}
					if (significant)
					{
						lsp.push_back(ovc_spiht_pixel(sx + 1, sy + 1));
						bitstream->write_bit(((int64_t)in_matrix(sy + 1, sx + 1)) > 0 ? 0 : 1);
						if (++bit_cnt > bit_allocation)
						{
							return;
						}
					}
					else
					{
						lip.push_back(ovc_spiht_pixel(sx + 1, sy + 1));
					}
					// test if L(i, j) != 0
					get_successor(in_matrix, in_config.num_levels, sx, sy, &sx, &sy);
					if (sx != -1)
					{
						lis.push_back(ovc_spiht_set(lis[i].x, lis[i].y, OVC_SPIHT_TYPE_B));
					}
					lis.erase(lis.begin() + i);
					i--;
				}
			}
			else
			{
				bool significant = is_significant_set_B(in_matrix, in_config.num_levels, lis[i].x, lis[i].y, step);
				bitstream->write_bit((uint8_t)significant);
				if (++bit_cnt > bit_allocation)
				{
					return;
				}
				if (significant)
				{
					int64_t sx, sy;
					get_successor(in_matrix, in_config.num_levels, lis[i].x, lis[i].y, &sx, &sy);
					lis.push_back(ovc_spiht_set(sx, sy, OVC_SPIHT_TYPE_A));
					lis.push_back(ovc_spiht_set(sx + 1, sy, OVC_SPIHT_TYPE_A));
					lis.push_back(ovc_spiht_set(sx, sy + 1, OVC_SPIHT_TYPE_A));
					lis.push_back(ovc_spiht_set(sx + 1, sy + 1, OVC_SPIHT_TYPE_A));
					lis.erase(lis.begin() + i);
					i--;
				}
			}
		}
		// refinement pass
		for (int64_t i = 0; i < lsp.size(); i++)
		{
			if (std::abs((int64_t)in_matrix(lsp[i].y, lsp[i].x)) >= (1 << (step + 1)))
			{
				bitstream->write_bit((((int64_t)std::abs((int64_t)in_matrix(lsp[i].y, lsp[i].x))) >> step) & 1);
				if (++bit_cnt > bit_allocation)
				{
					return;
				}
			}
		}
		// update quantization step
		step--;
	}

	// Pad the bitstream to the allocation amount as that's what the decoder is expecting
	while (bitstream->size() < bit_allocation)
	{
		// TODO (belchy06): Figure out a way to not need padding
		bitstream->write_bit(0);
	}
}

void spiht_encoder::flush(uint8_t** out_bytes, uint16_t* out_step)
{
	*out_bytes = new uint8_t[bitstream->occupancy()];
	memcpy(*out_bytes, bitstream->data(), bitstream->occupancy());

	*out_step = output_step;

	clear();
}

void spiht_encoder::clear()
{
	delete bitstream;
	lip.clear();
	lsp.clear();
	lis.clear();

	output_step = 0;
	bitstream = new ovc_bitstream();
}

void spiht_encoder::get_successor(matrix<double>& in_matrix, size_t in_num_levels, int64_t in_x, int64_t in_y, int64_t* out_sx, int64_t* out_sy)
{
	int64_t lx = (in_matrix.get_num_columns()) / (1 << in_num_levels);
	int64_t ly = (in_matrix.get_num_rows()) / (1 << in_num_levels);
	if (in_x < lx && in_y < ly)
	{
		if (in_x % 2 == 1)
			*out_sx = in_x + lx - 1;
		else
			*out_sx = in_x;
		if (in_y % 2 == 1)
			*out_sy = in_y + ly - 1;
		else
			*out_sy = in_y;
		if (*out_sx == in_x && *out_sy == in_y)
		{
			*out_sx = -1;
			*out_sy = -1;
		}
	}
	else
	{
		*out_sx = 2 * in_x;
		*out_sy = 2 * in_y;
		if (*out_sx >= (in_matrix.get_num_columns()) || *out_sy >= (in_matrix.get_num_rows()))
		{
			*out_sx = -1;
			*out_sy = -1;
		}
	}
}

bool spiht_encoder::is_significant_pixel(matrix<double>& in_matrix, int64_t in_x, int64_t in_y, uint16_t in_step)
{
	return std::abs((int64_t)in_matrix(in_y, in_x)) >= (1 << in_step);
}

bool spiht_encoder::is_significant_set_A(matrix<double>& in_matrix, size_t in_num_levels, int64_t in_x, int64_t in_y, uint16_t in_step, int64_t in_count)
{
	if (in_count > 1 && is_significant_pixel(in_matrix, in_x, in_y, in_step))
		return true;
	int64_t sx, sy;
	get_successor(in_matrix, in_num_levels, in_x, in_y, &sx, &sy);
	if (sx == -1 || sy == -1)
		return false;
	if (is_significant_set_A(in_matrix, in_num_levels, sx, sy, in_step, in_count + 1))
		return true;
	else if (is_significant_set_A(in_matrix, in_num_levels, sx + 1, sy, in_step, in_count + 1))
		return true;
	else if (is_significant_set_A(in_matrix, in_num_levels, sx, sy + 1, in_step, in_count + 1))
		return true;
	else if (is_significant_set_A(in_matrix, in_num_levels, sx + 1, sy + 1, in_step, in_count + 1))
		return true;
	return false;
}

bool spiht_encoder::is_significant_set_B(matrix<double>& in_matrix, size_t in_num_levels, int64_t in_x, int64_t in_y, uint16_t in_step, int64_t in_count)
{
	if (in_count > 2 && is_significant_pixel(in_matrix, in_x, in_y, in_step))
		return true;
	int64_t sx, sy;
	get_successor(in_matrix, in_num_levels, in_x, in_y, &sx, &sy);
	if (sx == -1 || sy == -1)
		return false;
	if (is_significant_set_B(in_matrix, in_num_levels, sx, sy, in_step, in_count + 1))
		return true;
	else if (is_significant_set_B(in_matrix, in_num_levels, sx + 1, sy, in_step, in_count + 1))
		return true;
	else if (is_significant_set_B(in_matrix, in_num_levels, sx, sy + 1, in_step, in_count + 1))
		return true;
	else if (is_significant_set_B(in_matrix, in_num_levels, sx + 1, sy + 1, in_step, in_count + 1))
		return true;
	return false;
}

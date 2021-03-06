/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2014 - Hans-Kristian Arntzen
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RARCH_FILTER_H__
#define RARCH_FILTER_H__

#include "../libretro.h"
#include <stddef.h>

#include "filters/softfilter.h"

#define RARCH_SOFTFILTER_THREADS_AUTO 0
typedef struct rarch_softfilter rarch_softfilter_t;

rarch_softfilter_t *rarch_softfilter_new(const char *filter_path,
      unsigned threads,
      enum retro_pixel_format in_pixel_format,
      unsigned max_width, unsigned max_height);

void rarch_softfilter_free(rarch_softfilter_t *filt);

void rarch_softfilter_get_max_output_size(rarch_softfilter_t *filt,
      unsigned *width, unsigned *height);

void rarch_softfilter_get_output_size(rarch_softfilter_t *filt,
      unsigned *out_width, unsigned *out_height,
      unsigned width, unsigned height);

enum retro_pixel_format rarch_softfilter_get_output_format(rarch_softfilter_t *filt);

void rarch_softfilter_process(rarch_softfilter_t *filt,
      void *output, size_t output_stride,
      const void *input, unsigned width, unsigned height, size_t input_stride);

const char *rarch_softfilter_get_name(rarch_softfilter_t *filt);

enum
{
   SOFTFILTER_NONE = 0,
   SOFTFILTER_TWOXBR,
   SOFTFILTER_DARKEN,
   SOFTFILTER_EPX,
   SOFTFILTER_TWOXSAI,
   SOFTFILTER_SUPERTWOXSAI,
   SOFTFILTER_SUPEREAGLE,
   SOFTFILTER_SCALE2X,
   SOFTFILTER_LAST,
};

#ifdef HAVE_FILTERS_BUILTIN
const struct softfilter_implementation *twoxbr_get_implementation(softfilter_simd_mask_t simd);
const struct softfilter_implementation *epx_get_implementation(softfilter_simd_mask_t simd);
const struct softfilter_implementation *twoxsai_get_implementation(softfilter_simd_mask_t simd);
const struct softfilter_implementation *supereagle_get_implementation(softfilter_simd_mask_t simd);
const struct softfilter_implementation *supertwoxsai_get_implementation(softfilter_simd_mask_t simd);
const struct softfilter_implementation *twoxbr_get_implementation(softfilter_simd_mask_t simd);
const struct softfilter_implementation *darken_get_implementation(softfilter_simd_mask_t simd);
const struct softfilter_implementation *scale2x_get_implementation(softfilter_simd_mask_t simd);
#endif

#endif


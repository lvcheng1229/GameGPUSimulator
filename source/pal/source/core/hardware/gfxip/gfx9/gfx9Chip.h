/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2015-2024 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 **********************************************************************************************************************/

#pragma once
#include "chip/gfx9_plus_merged_offset.h"
#include "chip/gfx9_plus_merged_default.h"
#include "chip/gfx9_plus_merged_enum.h"
#include "chip/gfx9_plus_merged_mask.h"
#include "chip/gfx9_plus_merged_shift.h"
#include "chip/gfx9_plus_merged_registers.h"
#include "chip/gfx9_plus_merged_typedef.h"

#include "chip/gfx9_plus_merged_f32_ce_pm4_packets.h"  // constant engine
#include "chip/gfx9_plus_merged_f32_mec_pm4_packets.h" // compute engine
#include "chip/gfx9_plus_merged_f32_me_pm4_packets.h"  // micro-engine
#include "chip/gfx9_plus_merged_f32_pfp_pm4_packets.h" // pre-fetch-parser
#include "chip/gfx9_plus_merged_pm4_it_opcodes.h"

#include "chip/gfx10_sq_ko_reg.h"

namespace Pal
{
	namespace Gfx9
	{
        using SQ_BUF_RSRC_WORD0 = Pal::Gfx9::SQ_BUF_RSRC_WORD0;
        using SQ_BUF_RSRC_WORD1 = Pal::Gfx9::SQ_BUF_RSRC_WORD1;
        using SQ_BUF_RSRC_WORD2 = Pal::Gfx9::SQ_BUF_RSRC_WORD2;
        using SQ_BUF_RSRC_WORD3 = Pal::Gfx9::SQ_BUF_RSRC_WORD3;

        using sq_buf_rsrc_t = Pal::Gfx9::Chip::sq_buf_rsrc_t;


        struct Gfx9BufferSrd
        {
            SQ_BUF_RSRC_WORD0 word0;
            SQ_BUF_RSRC_WORD1 word1;
            SQ_BUF_RSRC_WORD2 word2;
            SQ_BUF_RSRC_WORD3 word3;
        };

        // Buffer resource descriptor structure
        union BufferSrd
        {
            Gfx9BufferSrd  gfx9;
            sq_buf_rsrc_t  gfx10;
        };

        enum Pm4ShaderType : unsigned int
        {
            ShaderGraphics = 0,
            ShaderCompute = 1
        };

        // This enum defines the predicate value supported in PM4 type 3 header
        enum Pm4Predicate : unsigned int
        {
            PredDisable = 0,
            PredEnable = 1
        };
	}
}
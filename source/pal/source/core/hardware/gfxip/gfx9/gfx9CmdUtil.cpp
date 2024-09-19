#include "gfx9CmdUtil.h"
#include "utility/palInlineFuncs.h"

using namespace utility;
namespace Pal
{
	namespace Gfx9
	{
        static PM4_ME_TYPE_3_HEADER Type3Header(
            IT_OpCodeType  opCode,
            uint32         count,
            bool           resetFilterCam = false,
            Pm4ShaderType  shaderType = ShaderGraphics,
            Pm4Predicate   predicate = PredDisable)
        {
            // PFP and ME headers are the same structure...  doesn't really matter which one we use.
            PM4_ME_TYPE_3_HEADER  header = {};

            header.predicate = predicate;
            header.shaderType = shaderType;
            header.type = 3; // type-3 packet
            header.opcode = opCode;
            header.count = (count - 2);
            header.resetFilterCam = resetFilterCam;

            return header;
        }

		size_t BuildDrawIndex2(uint32 indexCount, uint32 indexBufSize, gpusize indexBufAddr, Pm4Predicate predicate, void* pBuffer)
		{
			constexpr uint32 PacketSize = PM4_PFP_DRAW_INDEX_2_SIZEDW__CORE;
			auto* const       pPacket = static_cast<PM4_PFP_DRAW_INDEX_2*>(pBuffer);
			pPacket->ordinal1.header.u32All = (Type3Header(IT_DRAW_INDEX_2, PacketSize,false, ShaderGraphics, predicate)).u32All;
            pPacket->ordinal2.max_size = indexBufSize;
            pPacket->ordinal3.index_base_lo = LowPart(indexBufAddr);
            pPacket->ordinal4.index_base_hi = HighPart(indexBufAddr);
            pPacket->ordinal5.index_count = indexCount;

            regVGT_DRAW_INITIATOR drawInitiator;
            drawInitiator.u32All = 0;
            drawInitiator.bits.SOURCE_SELECT = DI_SRC_SEL_DMA;
            drawInitiator.bits.MAJOR_MODE = DI_MAJOR_MODE_0;

            pPacket->ordinal6.draw_initiator = drawInitiator.u32All;
            return PacketSize;
		}
	}
}

#include "gfx9UniversalCmdBuffer.h"
#include "gfx9Chip.h"

namespace Pal
{
	namespace Gfx9
	{
		void Pal::Gfx9::UniversalCmdBuffer::CmdSetVertexBuffers(uint32 firstBuffer, uint32 bufferCount, const BufferViewInfo* pBuffers)
		{
			//BufferSrd* const pSrds = ;

		}

		void UniversalCmdBuffer::CmdDrawIndexed(ICmdBuffer* pCmdBuffer, uint32 firstIndex, uint32 indexCount, int32 vertexOffset, uint32 firstInstance, uint32 instanceCount, uint32 drawId)
		{
			//pDeCmdSpace += CmdUtil::BuildDrawIndex2(indexCount,
			//	validIndexCount,
			//	gpuVirtAddr,
			//	pThis->PacketPredicate(),
			//	pDeCmdSpace);
		}
	}
}


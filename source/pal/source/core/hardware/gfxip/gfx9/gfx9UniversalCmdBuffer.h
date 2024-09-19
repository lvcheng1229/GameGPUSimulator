#pragma once
#include "../source/core/hardware/gfxip/pm4/pm4UniversalCmdBuffer.h"
namespace Pal
{
	namespace Gfx9
	{
		class UniversalCmdBuffer : public Pal::Pm4::UniversalCmdBuffer
		{
		public:
			virtual void CmdSetVertexBuffers(
				uint32                firstBuffer,
				uint32                bufferCount,
				const BufferViewInfo* pBuffers) override;

			static void CmdDrawIndexed(
				ICmdBuffer* pCmdBuffer,
				uint32      firstIndex,
				uint32      indexCount,
				int32       vertexOffset,
				uint32      firstInstance,
				uint32      instanceCount,
				uint32      drawId);
		};
	}
};
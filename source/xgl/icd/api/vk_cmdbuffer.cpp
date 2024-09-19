#include "vulkan/vulkan.h"
#include "vk_cmdbuffer.h"

namespace vk
{
	void CmdBuffer::DrawIndexed(uint32_t firstIndex, uint32_t indexCount, int32_t vertexOffset, uint32_t firstInstance, uint32_t instanceCount)
	{
		PalCmdDrawIndexed(firstIndex,
			indexCount,
			vertexOffset,
			firstInstance,
			instanceCount,
			0u);
	}

	void CmdBuffer::PalCmdDrawIndexed(uint32_t firstIndex, uint32_t indexCount, int32_t vertexOffset, uint32_t firstInstance, uint32_t instanceCount, uint32_t drawId)
	{
	}
}

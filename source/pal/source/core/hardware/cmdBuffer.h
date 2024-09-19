#pragma once
#include "core/pal.h"
#include "core/palCmdBuffer.h"
#include "ggsCommon.h"

namespace Pal
{
	class CmdBuffer : public ICmdBuffer
	{
	public:
		virtual void CmdSetVertexBuffers(uint32 firstBuffer, uint32 bufferCount, const BufferViewInfo* pBuffers) override { assert(false); }
	};
}
/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2014-2024 Advanced Micro Devices, Inc. All Rights Reserved.
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
#include "pal.h"
#include "palDevice.h"
namespace Pal
{


    class ICmdBuffer
    {
    public:
        typedef void (*CmdDrawIndexedFunc)(
            ICmdBuffer* pCmdBuffer,
            uint32      firstIndex,
            uint32      indexCount,
            int32       vertexOffset,
            uint32      firstInstance,
            uint32      instanceCount,
            uint32      drawId);

        virtual void CmdSetVertexBuffers(
            uint32                firstBuffer,
            uint32                bufferCount,
            const BufferViewInfo* pBuffers) = 0;

        void CmdDrawIndexed(
            uint32 firstIndex,
            uint32 indexCount,
            int32  vertexOffset,
            uint32 firstInstance,
            uint32 instanceCount,
            uint32 drawId)
        {
            m_funcTable.pfnCmdDrawIndexed(this, firstIndex, indexCount, vertexOffset, firstInstance, instanceCount, drawId);
        };

    protected:
        struct CmdBufferFnTable
        {
            CmdDrawIndexedFunc               pfnCmdDrawIndexed;
        }m_funcTable;
    private:
    };
}

#pragma once
#include "../../queue.h"
namespace Pal
{
    namespace Amdgpu
    {
        class Queue : public Pal::Queue
        {
            virtual Result OsSubmit(const MultiSubmitInfo& submitInfo, const InternalSubmitInfo* pInternalSubmitInfos) override;

            Result SubmitIbs(const InternalSubmitInfo& internalSubmitInfo);
        };
    }
   
}

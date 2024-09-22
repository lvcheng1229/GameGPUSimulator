#include "amdgpuQueue.h"
#include "amdgpu_internal.h"

namespace Pal
{
    namespace Amdgpu
    {
        Result Pal::Amdgpu::Queue::OsSubmit(const MultiSubmitInfo& submitInfo, const InternalSubmitInfo* pInternalSubmitInfos)
        {
            return Result();
        }

        Result Queue::SubmitIbs(const InternalSubmitInfo& internalSubmitInfo)
        {
            return Result();
        }

    }
}

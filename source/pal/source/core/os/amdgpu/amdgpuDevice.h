#pragma once
#include "../../device.h"
#include "amdgpu.h"

namespace Pal
{
namespace Amdgpu
{
    class Device : public Pal::Device
    {
    public:

        Result SubmitRaw2(
            amdgpu_context_handle           hContext,
            uint32                          bo_list_handle,
            uint32                          chunkCount,
            struct drm_amdgpu_cs_chunk* pChunks,
            uint64* pFence) const;

        Result Submit(
            amdgpu_context_handle     hContext,
            uint64                    flags,
            struct amdgpu_cs_request* pIbsRequest,
            uint32                    numberOfRequests,
            uint64* pFences) const;
    };
}
}
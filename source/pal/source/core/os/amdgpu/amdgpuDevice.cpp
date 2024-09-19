
namespace Pal
{
	namespace Amdgpu
	{
		Result Device::SubmitRaw2(amdgpu_context_handle hContext, uint32 bo_list_handle, uint32 chunkCount, drm_amdgpu_cs_chunk* pChunks, uint64* pFence) const
		{
			return Result();
		}

		Result Device::Submit(amdgpu_context_handle hContext, uint64 flags, amdgpu_cs_request* pIbsRequest, uint32 numberOfRequests, uint64* pFences) const
		{
			return Result();
		}
	}
}

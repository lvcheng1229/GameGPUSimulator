#include <malloc.h>
#include "amdgpu.h"
#include "amdgpu_internal.h"

int amdgpu_cs_submit_raw2(amdgpu_device_handle dev, amdgpu_context_handle context, uint32_t bo_list_handle, int num_chunks, struct drm_amdgpu_cs_chunk* chunks, uint64_t* seq_no)
{
	union drm_amdgpu_cs cs = { 0 };
	uint64_t* chunk_array;
	int i, r;

	chunk_array = (uint64_t*)alloca(sizeof(uint64_t) * num_chunks);
	for (i = 0; i < num_chunks; i++)
		chunk_array[i] = (uint64_t)(uintptr_t)&chunks[i];
	cs.in.chunks = (uint64_t)(uintptr_t)chunk_array;
	cs.in.ctx_id = context->id;
	cs.in.bo_list_handle = bo_list_handle;
	cs.in.num_chunks = num_chunks;
	r = drmCommandWriteRead(dev->fd, DRM_AMDGPU_CS,
		&cs, sizeof(cs));
	if (!r && seq_no)
		*seq_no = cs.out.handle;
	return r;
}
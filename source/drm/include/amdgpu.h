#pragma once
#include "xf86drm.h"
#include "amdgpu_drm.h"

typedef struct amdgpu_device* amdgpu_device_handle;
typedef struct amdgpu_context* amdgpu_context_handle;

int amdgpu_cs_submit_raw2(amdgpu_device_handle dev, amdgpu_context_handle context, uint32_t bo_list_handle, int num_chunks, struct drm_amdgpu_cs_chunk *chunks, uint64_t *seq_no);
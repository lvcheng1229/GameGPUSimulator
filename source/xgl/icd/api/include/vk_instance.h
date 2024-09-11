#pragma once
#include "vulkan/vulkan_core.h"
namespace vk
{

    class Instance
    {
    public:
        inline static Instance* ObjectFromHandle(VkInstance handle)
        {
            return reinterpret_cast<Instance*>(handle);
        }

        VkResult Destroy(void);

        static VkResult Create(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
    };

    namespace entry
    {
        VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
        VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);
    }
}

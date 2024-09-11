#include "include/vk_instance.h"
#include "include/vk_common.h"

namespace vk
{
    VkResult Instance::Destroy(void)
    {
        return VK_SUCCESS;
    }

    VkResult Instance::Create(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
    {
        const VkAllocationCallbacks* pAllocCb = pAllocator;

        if (pAllocCb == nullptr)
        {

        }
        else { vk_assert(false); }

        VkResult result = VK_SUCCESS;

        return result;
    }

    namespace entry
    {
        VKAPI_ATTR VkResult VKAPI_CALL entry::vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
        {
            return Instance::Create(pCreateInfo, pAllocator, pInstance);
        }

        VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
        {
            if (instance != VK_NULL_HANDLE)
            {
                Instance::ObjectFromHandle(instance)->Destroy();
            }
        }
    }
}


extern "C"
{
    VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(
        const VkInstanceCreateInfo* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkInstance* pInstance)
    {
        return vk::entry::vkCreateInstance(pCreateInfo, pAllocator, pInstance);
    }

    VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(
        VkInstance  instance,
        const VkAllocationCallbacks* pAllocator)
    {
        return vk::entry::vkDestroyInstance(instance, pAllocator);
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices)
    {
        return VkResult();
    }

    VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(
        uint32_t* pPropertyCount,
        VkLayerProperties* pProperties)
    {
        return VkResult();
    }
}

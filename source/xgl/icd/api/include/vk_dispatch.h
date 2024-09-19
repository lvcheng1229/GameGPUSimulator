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
#include "khronos/sdk-1.3/vulkan/vk_icd.h"
#include "vk_utils.h"

namespace vk
{

    template <typename C>
    class Dispatchable
    {
    private:
        VK_LOADER_DATA m_reservedForLoader;
        unsigned char  m_C[sizeof(C)];

    protected:
        Dispatchable()
        {
            m_reservedForLoader.loaderMagic = ICD_LOADER_MAGIC;
        }

    public:
        VK_FORCEINLINE C* operator->()
        {
            return (C*)&m_C[0];
        }

        VK_FORCEINLINE const C* operator->() const
        {
            return (const C*)&m_C[0];
        }

        VK_FORCEINLINE operator C* ()
        {
            return (C*)&m_C[0];
        }

        VK_FORCEINLINE operator const C* () const
        {
            return (const C*)&m_C[0];
        }

        // Given pointer to const C, returns the containing Dispatchable<C>.
        static VK_FORCEINLINE const Dispatchable<C>* FromObject(const C* it)
        {
            return reinterpret_cast<const Dispatchable<C>*>(
                reinterpret_cast<const uint8_t*>(it) - (sizeof(Dispatchable<C>) - sizeof(C))
                );
        }

        // Non-const version of above.
        static VK_FORCEINLINE Dispatchable<C>* FromObject(C* it)
        {
            return reinterpret_cast<Dispatchable<C>*>(
                reinterpret_cast<uint8_t*>(it) - (sizeof(Dispatchable<C>) - sizeof(C))
                );
        }

        // Converts a "Vk*" dispatchable handle to the driver internal object pointer.
        static VK_FORCEINLINE C* ObjectFromHandle(typename C::ApiType handle)
        {
            return reinterpret_cast<C*>(
                reinterpret_cast<Dispatchable<C>*>(handle)->m_C);
        }

        static VK_FORCEINLINE uint64_t IntValueFromHandle(Dispatchable<C>* handle)
        {
            return reinterpret_cast<uint64_t>(handle);
        }
    };

}
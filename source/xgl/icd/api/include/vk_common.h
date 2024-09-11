#pragma once
#define GGPUSIM_DEBUG 1
#ifdef GGPUSIM_DEBUG
#include <assert.h>
#define vk_assert(x) assert(x)
#else
#define vk_assert(x)
#endif
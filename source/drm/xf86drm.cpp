#include <errno.h>
#include <assert.h>
#include "xf86drm.h"
#include "gpu_device.h"

int drmIoctl(int fd, unsigned long request, void* arg)
{
    int ret;

    do {
        ret = ioctl(fd, request, arg);
    } while (ret == -1 && (errno == EINTR || errno == EAGAIN));
    return ret;
}

int drmCommandWriteRead(int fd, unsigned long drmCommandIndex, void* data, unsigned long size)
{
    unsigned long request;

    //request = DRM_IOC(DRM_IOC_READ | DRM_IOC_WRITE, DRM_IOCTL_BASE, DRM_COMMAND_BASE + drmCommandIndex, size);
    request = 0;
    assert(false);


    if (drmIoctl(fd, request, data))
        return -errno;
    return 0;
}
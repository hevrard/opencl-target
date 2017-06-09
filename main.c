#ifdef __APPLE__
  #include <OpenCL/OpenCL.h>
#else
  #include <CL/cl.h>
#endif

#include "opencl_target.h"

enum { STRLEN = 128 };

int main(int argc, char **argv)
{
    cl_platform_id platform_id;
    cl_device_id   device_id;
    opencl_target_init(&platform_id, &device_id);

    char platform_name[STRLEN];
    clGetPlatformInfo(platform_id, CL_PLATFORM_NAME, STRLEN, platform_name, NULL);
    printf("Platform: %s\n", platform_name);

    char device_name[STRLEN];
    clGetDeviceInfo(device_id, CL_DEVICE_NAME, STRLEN, device_name, NULL);
    printf("Device  : %s\n", device_name);

    return EXIT_SUCCESS;
}

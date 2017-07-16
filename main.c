#ifdef __APPLE__
  #include <OpenCL/OpenCL.h>
#else
  #include <CL/cl.h>
#endif

#include "opencl_target.h"

enum { STRLEN = 128 };

int main(int argc, char **argv)
{
    cl_platform_id platform_id = NULL;
    cl_device_id   device_id   = NULL;

    if (argc == 1) {
        opencl_target_env(&platform_id, &device_id);
    } else  {
        opencl_target_str(&platform_id, &device_id, argv[1]);
    }

    if (device_id == NULL) {
        printf("No matching device found!\n");
        return EXIT_FAILURE;
    }

    char platform_name[STRLEN];
    clGetPlatformInfo(platform_id, CL_PLATFORM_NAME, STRLEN, platform_name, NULL);
    printf("Platform: %s\n", platform_name);

    char device_name[STRLEN];
    clGetDeviceInfo(device_id, CL_DEVICE_NAME, STRLEN, device_name, NULL);
    printf("Device  : %s\n", device_name);

    char device_version[STRLEN];
    clGetDeviceInfo(device_id, CL_DEVICE_VERSION, STRLEN, device_version, NULL);
    printf("Version : %s\n", device_version);

    return EXIT_SUCCESS;
}

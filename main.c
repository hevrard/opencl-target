// Copyright (c) 2017 Hugues Evrard, MIT License

#include "opencl_target.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    cl_platform_id platform;
    cl_device_id device;
    opencl_target_init(&platform, &device);
    printf("Platform id: %x\n", platform);
    printf("Device id: %x\n", device);
    return 0;
}

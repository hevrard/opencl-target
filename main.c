// Copyright (c) 2017 Hugues Evrard, MIT License

#include "opencl_target.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    cl_device_id id = opencl_target_device_id();
    printf("Device id: %x\n", id);
    return 0;
}

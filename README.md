# opencl_target
OpenCL execution target selector.

One can specify the OpenCL target using the `OPENCL_TARGET_DEVICE`
environment variable, e.g.:

    $ OPENCL_TARGET_DEVICE="OpenCL 2.0 beignet 1.3"
    $ export OPENCL_TARGET_DEVICE
    $ ./your-opencl-application   # will target the above device

The OpenCL platforms are searched for a device whose *VERSION*
(`CL_DEVICE_VERSION`) string *contains* the value of
`OPENCL_TARGET_DEVICE`. If `OPENCL_TARGET_DEVICE` is unset, it is
equivalent to having its value set as an empty string: the first device
encountered will be used.

## How to use

Include the `opencl_target.h` header, and use the
`opencl_target_device_id(void)` primitive to retrieve the device ID:

    #include "opencl_target.h"

    int main() {
        cl_device_id device_id = opencl_target_device_id();
        ...
    }

See the included `main.c` and `Makefile` for a minimal example.

## Where to get the version strings

You can use the `clinfo` tool to get an overview of the OpenCL platform
and devices available on a machine. Remember, opencl_target will search
for a substring inside the device version string, which so far seems to
contains enough information to uniquely identify a device.

# opencl_target

OpenCL execution target selector.

Specify the OpenCL target using the `OPENCL_TARGET_DEVICE` environment
variable. For instance:

    $ clinfo | grep 'Device Version'
    Device Version    OpenCL 2.0 beignet 1.3
    Device Version    OpenCL 1.2 beignet 1.3
    Device Version    OpenCL 2.0 pocl HSTR: pthread-x86_64-pc-linux-gnu-skylake
    $ OPENCL_TARGET_DEVICE="OpenCL 2.0 beignet 1.3"
    $ export OPENCL_TARGET_DEVICE
    $ ./your-opencl-application   # will target the above device

The OpenCL platforms are searched for a device whose *VERSION*
(`CL_DEVICE_VERSION`) string *contains* the value of
`OPENCL_TARGET_DEVICE`. If `OPENCL_TARGET_DEVICE` is unset, it is
equivalent to having its value set as an empty string: any device will
match, so the first device encountered will be used.

## How to use

Include the `opencl_target.h` header, and use the
`opencl_target_init(cl_platform_id *platform_id, cl_device_id
*device_id)` primitive to retrieve both platform and device id:

```C
#include <CL/cl.h> // Must be included before

#include "opencl_target.h"

int main() {
    cl_platform_id platform_id;
    cl_device_id   device_id;
    opencl_target_init(&platform_id, &device_id);
    ...
}
```

See the included `main.c` and `Makefile` for a minimal example.

## Where to get the version strings

You can use the `clinfo` tool to get an overview of the OpenCL platform
and devices available on a machine. Remember, opencl_target will search
for a substring inside the device version string, which so far seems to
contains enough information to uniquely identify a device.

# TODO

 - test on Mac

 - add a primitive where the target string is passed as argument

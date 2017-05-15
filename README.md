# opencl-target
OpenCL execution target selector

## What it enables

One can specify the OpenCL target using the `OPENCL_TARGET_DEVICE`
environment variable, e.g.:

    $ OPENCL_TARGET_DEVICE="OpenCL 2.0 beignet 1.3"
    $ export OPENCL_TARGET_DEVICE
    $ ./your-opencl-application   # will target the above device

The OpenCL platforms are searched for a device whose *version* string
_contains_ the value of `OPENCL_TARGET_DEVICE`. If
`OPENCL_TARGET_DEVICE`, it looks for a match of the empty string, thus
it will return the first device encountered.

## How to use

To use in your code, just include the header, and use its primitive to
retrieve the device id:

    #include "opencl_target.h"

    int main() {
        cl_device_id device_id = opencl_target_device_id();
        ...
    }

See the included `main.c` and `Makefile` for a minimal example.

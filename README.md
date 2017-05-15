# opencl-target
OpenCL execution target selector

One can specify the OpenCL target using the `OPENCL_TARGET_DEVICE`
environment variable, e.g.:

    OPENCL_TARGET_DEVICE="OpenCL 2.0 beignet 1.3"
    export OPENCL_TARGET_DEVICE

    ./your-opencl-application   # will target the above device

To use in your code, just include the header, and use its primitive to
retrieve the device id:

    #include "opencl_target.h"

    ...

    int main() {

        ...

        cl_device_id = opencl_target_device_id();

    }

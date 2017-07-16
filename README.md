# opencl_target

Header library that makes selecting an OpenCL target easier.

Tired of passing platform and device IDs to your OpenCL programs? This
library makes it easy to select a platform & device pair from a single
string. This string is called the **target string**, and the library
will return the first platform & device pair where the **device
version** string **contains** the target string.  This target string can
be passed explicitely, or retrieved from the `OPENCL_TARGET` environment
variable.

## API

### `opencl_target_str()`

```C
void opencl_target_str(cl_platform_id *platform_id, cl_device_id *device_id, char *target)
```

Look for an OpenCL device version string which contains `target`. If
found, set `platform_id` and `device_id` accordingly. If not found, set
both `platform_id` and `device_id` to `NULL`. In case of internal error,
print an error message to standard output and abort.

### `opencl_target_env()`

```C
void opencl_target_env(cl_platform_id *platform_id, cl_device_id *device_id)
```

Behave similarly to `opencl_target_str()`, passing the value of the
`OPENCL_TARGET` environment variable as the target string. If this
environment variable is not set, pass the empty string, which results in
whichever device that comes first to be selected.

## Example

See the included `main.c` and associated `Makefile` for a small example.

### Writing a program using opencl_target

Include the `opencl_target.h` header, and use the
`opencl_target_env(cl_platform_id *platform_id, cl_device_id
*device_id)` primitive to retrieve both platform and device id from the
`OPENCL_TARGET` environment variable:

```C
#include <CL/cl.h> // Must be included before

#include "opencl_target.h"

int main() {
    cl_platform_id platform_id = NULL;
    cl_device_id   device_id   = NULL;
    opencl_target_env(&platform_id, &device_id);

    if (device_id == NULL) {
        // None of the available devices matches the target string!
        ...
    }
    ...
}
```

Alternatively, you can use the `opencl_target_str()` to pass the target
string explicitely.

### Executing this program on a particular OpenCL target

Specify the OpenCL target using the `OPENCL_TARGET` environment
variable. For instance:

```sh
$ clinfo | grep 'Device Version'
Device Version    OpenCL 2.0 beignet 1.3
Device Version    OpenCL 1.2 beignet 1.3
Device Version    OpenCL 2.0 pocl HSTR: pthread-x86_64-pc-linux-gnu-skylake
$ OPENCL_TARGET="OpenCL 2.0 beignet 1.3"
$ export OPENCL_TARGET
$ ./your-opencl-application   # will target the above device
```

The OpenCL platforms are searched for a device whose *VERSION*
(`CL_DEVICE_VERSION`) string *contains* the value of `OPENCL_TARGET`.

If `OPENCL_TARGET` environment variable is unset, it is equivalent to
having its value set as an empty string: any device will match, so the
first device encountered will be used.

## Where to get the version strings

You can use the `clinfo` tool to get an overview of the OpenCL platform
and devices available on a machine. Remember, `opencl_target` searches
for a substring inside the device version string. So far, it seems like
this device version string contains enough information to uniquely
identify a device. If you have a counter example, please let me know.


## TODO

 - test on Mac, Windows

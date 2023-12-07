# CPM

Very lightweight package manager for C++ to be used with CMake.

## What is it?

1. `fmt`: very simple example that depends on the `fmt` library
   that implements Python f-string like string formatting.


## How to use?

To build projects that use CPM, no special action is required:
```bash
$ cmake  -B build/  -S .
$ cmake  --build build/
```

Note that when you clean the build or remove the build directory CPM
and the build dependencies have to be downloaded and built again.

To use a source cache, configure CMake as follows:
```bash
$ cmake -B build/  -S .  -DCPM_SOURCE_CACHE=$HOME/cpm_cache
```

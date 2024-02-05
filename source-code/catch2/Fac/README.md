# Fac

Simple example of using Catch2 for C++ unit testing.  Illustrates testing
for expect function return values, and thrown exceptions.

## What is it?

1. `fac.cpp`: implementation of the factorial function.
1. `fac.h`: declaration of the factorial function.
1. `test_fac.cpp`: Catch2 tests for the factorial function.
1. `test_main.cpp`: main function to drive the tests.
1. `CMakeLists.txt`: CMake file to build the test appliation.


## How to use?

To build the application:
```bash
$ cmake  -B build/  -S .
$ cmake  --build build/
```

To run the tests:
```bash
$ cmake  --build build/  --target test
```
or
```bash
$ ctest  --test-dir build/

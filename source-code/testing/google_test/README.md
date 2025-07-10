# Simple

Very simple example of using Google Test for unit testing of C++ code.


## What is it?

1. `fib.h`: declaration of the C++ function to test.
1. `fib.cpp`: definition of the C++ function to test.
1. `test_fib.cpp`: implemenation of the tests for the Fibonacci function.
1. `CMakeLists.txt`: CMake file to build the project.


## How to use it?

Create the build files:
```bash
$ cmake  -B build/  -S .
```

*Note:* this will download Google Test from GitHub and place it in the `build/`
directory.  This requires internet access.


Build the project:
```bash
$ cmake --build build/
```

Run the tests:
```bash
$ ctest --test-dir build/
```

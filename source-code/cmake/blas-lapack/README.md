# BLAS and Lapack

BLAS and Lapack are mathematical libraries that are frequently used in HPC
codes.  CMake has direct support for finding these and linking to them.


## What is it?

1. `openblas`: CMake file to find OpenBLAS, and link to it.
1. `mkl`: CMake file to find Intel MKL, and link to it.
1. `mkl-specific`: CMake file specifically for MKL since the source code uses
   an MKL-specific API.

cmake_minimum_required(VERSION 3.0)

project(blas_lapack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra)

set(BLA_VENDOR Intel10_64lp)
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

add_executable(sgemm.exe sgemm.cpp)
target_link_libraries(sgemm.exe PUBLIC BLAS::BLAS)

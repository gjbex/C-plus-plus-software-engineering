cmake_minimum_required(VERSION 3.20)

project(openmp LANGUAGES CXX)

add_compile_options(-Wall -Wextra)

find_package(OpenMP)
add_executable(compute_pi.exe compute_pi.cpp)
if(OpenMP_CXX_FOUND)
    target_link_libraries(compute_pi.exe PUBLIC OpenMP::OpenMP_CXX)
endif()

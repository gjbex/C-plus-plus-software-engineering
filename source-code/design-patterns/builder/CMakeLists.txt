cmake_minimum_required(VERSION 3.14)

project(builder LANGUAGES CXX)

add_executable(rng_runner.exe
    rng.cpp
    rng_builder.cpp
    rng_runner.cpp
)

target_compile_features(rng_runner.exe PRIVATE cxx_std_14)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(rng_runner.exe PRIVATE -Wall -Wextra)
endif()

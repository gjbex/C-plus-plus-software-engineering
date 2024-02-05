cmake_minimum_required(VERSION 3.20)

project(fixtures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 REQUIRED)

add_executable(stack_test.exe
    stack_test.cpp)
target_link_libraries(stack_test Catch2::Catch2)

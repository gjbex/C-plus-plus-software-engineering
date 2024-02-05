cmake_minimum_required(VERSION 3.20)

project(simple_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 REQUIRED)

add_executable(simple_tests
    test_main.cpp fac.cpp test_fac.cpp)
target_link_libraries(simple_tests Catch2::Catch2)

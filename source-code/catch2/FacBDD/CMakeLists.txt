cmake_minimum_required(VERSION 3.20)

project(simple_bdd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 REQUIRED)

enable_testing()

add_executable(simple_tests.exe
    test_main.cpp fac.cpp test_fac.cpp)
target_link_libraries(simple_tests.exe Catch2::Catch2)

add_test(NAME simple_tests
    COMMAND simple_tests.exe)

add_executable(fac.exe
    fac_main.cpp fac.cpp)

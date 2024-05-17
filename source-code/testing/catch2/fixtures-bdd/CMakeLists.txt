cmake_minimum_required(VERSION 3.20)

project(fixtures_bdd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 REQUIRED)

enable_testing()

add_executable(stack_test.exe
    stack_test.cpp)
target_link_libraries(stack_test.exe Catch2::Catch2)

add_test(NAME stack_test
    COMMAND stack_test.exe)

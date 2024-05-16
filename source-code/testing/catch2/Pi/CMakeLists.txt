cmake_minimum_required(VERSION 3.20)

project(pi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 REQUIRED)

enable_testing()

add_executable(test_pi.exe
    test_main.cpp test_pi.cpp pi.cpp)
target_link_libraries(test_pi.exe Catch2::Catch2)

add_test(NAME test_pi COMMAND test_pi.exe)

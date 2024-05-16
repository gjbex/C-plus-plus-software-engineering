cmake_minimum_required(VERSION 3.20)

project(matchers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Catch2 REQUIRED)

enable_testing()

add_executable(ip_address.exe
    ip_address.cpp)

target_link_libraries(ip_address.exe
    PRIVATE
        Catch2::Catch2)

add_test(NAME ip_address
    COMMAND ip_address.exe)

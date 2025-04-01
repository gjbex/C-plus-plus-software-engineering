cmake_minimum_required(VERSION 3.20)

project(counter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(counter.exe
    counter_main.cpp
    utils.cpp)
target_link_libraries(counter.exe
    PRIVATE Boost::program_options)
target_include_directories(counter.exe
    PRIVATE Boost::program_options)
target_compile_options(counter.exe
    PRIVATE -Wall -Wextra -Wpedantic)

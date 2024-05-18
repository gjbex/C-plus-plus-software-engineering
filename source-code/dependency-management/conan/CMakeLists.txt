cmake_minimum_required(VERSION 3.22)

project(blaze_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(blaze REQUIRED)

add_executable(blaze_test.exe blaze_test.cpp)
target_link_libraries(blaze_test.exe PRIVATE blaze::blaze)

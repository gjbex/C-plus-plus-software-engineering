cmake_minimum_required(VERSION 3.0)

project(factory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(random_circles.exe random_circles.cpp circle.cpp circle_factory.cpp)

add_executable(circle_overlap.exe circle_overlap.cpp circle.cpp)

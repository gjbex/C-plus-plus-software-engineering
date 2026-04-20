cmake_minimum_required(VERSION 3.14)

project(factory LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.4.2
)

FetchContent_MakeAvailable(CLI11)

add_executable(random_circles.exe random_circles.cpp circle.cpp circle_factory.cpp)
target_link_libraries(random_circles.exe PRIVATE CLI11::CLI11)

add_executable(circle_overlap.exe circle_overlap.cpp circle.cpp)

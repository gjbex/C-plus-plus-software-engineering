cmake_minimum_required(VERSION 3.14)

project(strategy LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.4.2
)

FetchContent_MakeAvailable(CLI11)

add_executable(cellular_automaton.exe
    automaton_runner.cpp
    cycle_finder.cpp
    main.cpp
)

target_link_libraries(cellular_automaton.exe PRIVATE CLI11::CLI11)
target_compile_features(cellular_automaton.exe PRIVATE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(cellular_automaton.exe PRIVATE -Wall -Wextra -Wpedantic)
endif()

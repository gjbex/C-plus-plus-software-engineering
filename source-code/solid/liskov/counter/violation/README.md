# Liskov violation

Implementation of the absolute and relative counters such that the relative
counter is derived from the absolute counter, violating the Liskov substituion
principle.


## What is it?

1. `absolute_counter.h`: definition of the absolute counter class.
1. `absolute_counter.cpp`: implementation of the absolute counter class.
1. `relative_counter.h`: definition of the relative counter class, derived
   from the absolute counter..
1. `relative_counter.cpp`: implementation of the relative counter class.
1. `utils.h`: utility functions to parse command line arguments.
1. `utils.cpp`: implementation of the utility functions.
1. `counter_main.cpp`: main function that uses the absolute and relative
   counters.
1. `CMakeLists.txt`: CMake file to build the application.

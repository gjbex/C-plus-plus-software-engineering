# executable to build
add_executable(minimum minimum.cpp)

# link against GSL's libgsl and libgslcblas
target_link_libraries(minimum GSL::gsl GSL::gslcblas)
target_include_directories(minimum PRIVATE GSL::gsl)

# installation directives
install(TARGETS minimum
        RUNTIME
          DESTINATION bin
          COMPONENT runtime
       )

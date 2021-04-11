cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(test VERSION 0.1.0 LANGUAGES CXX)

set(sources value.hpp value.cpp)

add_library(value_object OBJECT EXCLUDE_FROM_ALL ${sources})
add_library(value_shared SHARED EXCLUDE_FROM_ALL ${sources})

add_executable(main main.cpp)
target_link_libraries(main PRIVATE debug value_shared optimized value_object)
target_compile_definitions(main PRIVATE $<$<CONFIG:Debug>:value_shared_IMPORTS>)

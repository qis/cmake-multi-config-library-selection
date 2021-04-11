cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(test VERSION 0.1.0 LANGUAGES CXX)

set(sources value.hpp value.cpp)

add_library(value_shared SHARED EXCLUDE_FROM_ALL ${sources})
add_library(value_static STATIC EXCLUDE_FROM_ALL ${sources})

add_library(value INTERFACE)
target_link_libraries(value INTERFACE debug value_shared optimized value_static)
#target_link_libraries(value INTERFACE $<IF:$<CONFIG:Debug>,value_shared,value_static>)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE value)
target_compile_definitions(main PRIVATE $<$<CONFIG:Debug>:value_shared_IMPORTS>)

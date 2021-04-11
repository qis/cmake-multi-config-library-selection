cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(test VERSION 0.1.0 LANGUAGES CXX)

add_library(value_object OBJECT value.hpp value.cpp)

add_library(value_shared SHARED EXCLUDE_FROM_ALL)
target_link_libraries(value_shared PUBLIC value_object)

add_library(value_static STATIC EXCLUDE_FROM_ALL)
target_link_libraries(value_static PUBLIC value_object)

add_library(value INTERFACE)
target_link_libraries(value INTERFACE optimized value_static)

# Debug builds and links to shared library.
# Release builds shared and static library, links to static library.
target_link_libraries(value INTERFACE debug value_shared)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE value)

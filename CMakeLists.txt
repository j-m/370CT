cmake_minimum_required(VERSION 3.10)
project(370CT VERSION 0.1.0)

add_subdirectory(projects/concurrency)
add_subdirectory(projects/distributed)
add_subdirectory(projects/parallel)
add_subdirectory(projects/rover)

include(CTest)
enable_testing()

cmake_minimum_required(VERSION 3.10)
project(Distributed VERSION 0.1.0)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/out)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_package(MPI REQUIRED)

file(GLOB_RECURSE src src/**.cpp)
add_executable(${PROJECT_NAME} ${src})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
target_link_libraries(${PROJECT_NAME} PUBLIC MPI::MPI_C)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

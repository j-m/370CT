cmake_minimum_required(VERSION 3.10)
project(Parallel VERSION 0.1.0)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/out)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

find_package(OpenMP REQUIRED)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

file(GLOB_RECURSE src src/**.cpp)
add_executable(${PROJECT_NAME} ${src})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

cmake_minimum_required(VERSION 3.10)
project(Parallel VERSION 0.1.0)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/out)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB_RECURSE src src/**.cpp)
add_executable(${PROJECT_NAME} ${src})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

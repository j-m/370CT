cmake_minimum_required(VERSION 3.10)
project(Concurrency VERSION 0.1.0)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/out)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

file(GLOB_RECURSE src src/**.cpp)
add_executable(${PROJECT_NAME} ${src})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${PROJECT_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

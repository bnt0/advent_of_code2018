cmake_minimum_required (VERSION 2.8.5)
project(day01)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(day01 main.cpp)

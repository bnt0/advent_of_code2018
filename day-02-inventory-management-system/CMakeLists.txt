cmake_minimum_required (VERSION 2.8.5)
project(day02)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC_FILES *.cpp)
add_executable(day02 ${SRC_FILES})

cmake_minimum_required(VERSION 2.8.5)
project(day03)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS *.cpp)
add_executable(day03 ${SRCS})

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(cmd)

enable_testing()
add_subdirectory(internal)


cmake_minimum_required(VERSION 3.10)
project(what_a_contest_gui)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O2 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -std=c++17 \
    -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align")


add_subdirectory(network)

set(NETWORK_Lib_LIB ${NETWORK_Lib_LIB} PARENT_SCOPE)
set(NETWORK_Lib_INCLUDE_DIRS ${NETWORK_Lib_INCLUDE_DIRS} PARENT_SCOPE)





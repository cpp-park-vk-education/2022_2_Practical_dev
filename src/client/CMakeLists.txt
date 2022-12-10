cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_subdirectory(internal)


message("NETWORK_Lib_LIB finally = ${NETWORK_Lib_LIB}")
message("NETWORK_Lib_INCLUDE_DIRS finally = ${NETWORK_Lib_INCLUDE_DIRS}")

set(NETWORK_Lib_LIB ${NETWORK_Lib_LIB} PARENT_SCOPE)
set(NETWORK_Lib_INCLUDE_DIRS ${NETWORK_Lib_INCLUDE_DIRS} PARENT_SCOPE)

add_subdirectory(cmd)


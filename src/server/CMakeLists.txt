cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)


enable_testing()
add_subdirectory(internal)

message("DB_Lib_LIB = ${DB_Lib_LIB}")
message("DB_Lib_INCLUDE_DIRS = ${DB_Lib_INCLUDE_DIRS}")

# set(DB_Lib_LIB ${DB_Lib_LIB} PARENT_SCOPE)
# set(DB_Lib_INCLUDE_DIRS ${DB_Lib_INCLUDE_DIRS} PARENT_SCOPE)

add_subdirectory(cmd)

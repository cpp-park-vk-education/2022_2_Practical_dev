cmake_minimum_required(VERSION 3.10)

project("DBLib")

set(LIB_NAME DB_Lib)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

message("SOURCES = ${SOURCES}")
message("HEADERS = ${HEADERS}")

set(PQXX /usr/local/include/pqxx)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -g -Wall -Wextra -O2 -pedantic -Wformat=2 -Wfloat-equal -Wconversion \
-Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpqxx -lpq")


add_library(${LIB_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${LIB_NAME} ${PQ_LIB} ${PQXX_LIB})

set(DB_Lib_LIB ${LIB_NAME})
set(DB_Lib_LIB ${DB_Lib_LIB} PARENT_SCOPE)
set(DB_Lib_INCLUDE_DIRS ${LIB_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(DB_Lib_INCLUDE_DIRS ${DB_Lib_INCLUDE_DIRS} PARENT_SCOPE)

message("DB_Lib_LIB = ${DB_Lib_LIB}")
message("DB_Lib_INCLUDE_DIRS = ${DB_Lib_INCLUDE_DIRS}")

enable_testing()
add_subdirectory(tests)

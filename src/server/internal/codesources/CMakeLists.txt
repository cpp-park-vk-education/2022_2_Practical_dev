cmake_minimum_required(VERSION 3.10)

project("Code_SourceLib")

set(LIB_NAME Code_Source_Lib)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h ${CMAKE_CURRENT_SOURCE_DIR}/virtual/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/virtual/*.h)

message("SOURCES = ${SOURCES}")
message("HEADERS = ${HEADERS}")

set(BOOST_ROOT /usr/include/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread)

find_package(nlohmann_json 3.7.0 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -g -Wall -Wextra -O2 -pedantic -Wformat=2 -Wfloat-equal -Wconversion \
-Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

include_directories(${Boost_INCLUDE_DIR})
add_library(${LIB_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/virtual ${Entities_Lib_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} ${Entities_Lib_LIB})

set(Code_Source_Lib_LIB ${LIB_NAME})
set(Code_Source_Lib_LIB ${Code_Source_Lib_LIB} PARENT_SCOPE)
set(Code_Source_Lib_INCLUDE_DIRS ${LIB_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/virtual)
set(Code_Source_Lib_INCLUDE_DIRS ${Code_Source_Lib_INCLUDE_DIRS} PARENT_SCOPE)

message("Code_Source_Lib_LIB = ${Code_Source_Lib_LIB}")
message("Code_Source_Lib_INCLUDE_DIRS = ${Code_Source_Lib_INCLUDE_DIRS}")

enable_testing()
add_subdirectory(tests)

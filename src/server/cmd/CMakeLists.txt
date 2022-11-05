cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "Server")

project(${PROJECT_NAME})

add_executable(Server main.cpp)
target_link_libraries(Server PRIVATE ${DB_Lib_LIB})
target_include_directories(Server PUBLIC ${DB_Lib_INCLUDE_DIRS})
message("BUILD SERVER")

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "Client")

project(${PROJECT_NAME})

add_executable(Client main.cpp)
target_link_libraries(Client PRIVATE ${NETWORK_Lib_LIB})
target_include_directories(Client PUBLIC ${NETWORK_Lib_INCLUDE_DIRS})

message("Client libraries include = ${NETWORK_Lib_INCLUDE_DIRS}")

message("BUILD CLIENT")
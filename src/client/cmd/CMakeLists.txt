cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "Client")

project(${PROJECT_NAME})

add_executable(Client main.cpp)
target_link_libraries(Client PRIVATE ${NumbersCounterLib_LIB})
target_include_directories(Client PUBLIC ${NumbersCounterLib_INCLUDE_DIRS})
message("BUILD CLIENT")

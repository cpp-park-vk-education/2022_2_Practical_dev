cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "Server")

project(${PROJECT_NAME})

add_executable(Server main.cpp)
target_link_libraries(Server PRIVATE ${DB_Lib_LIB} ${Runner_Lib_LIB} ${Checker_Lib_LIB} PUBLIC server utils)
target_include_directories(Server PUBLIC ${DB_Lib_INCLUDE_DIRS} ${Runner_Lib_INCLUDE_DIRS} ${Checker_Lib_INCLUDE_DIRS})
message("Built server")

# add_executable(Checker checker.cpp)
# target_link_libraries(Checker PRIVATE ${Checker_Lib_LIB})
# target_include_directories(Checker PUBLIC ${Checker_Lib_INCLUDE_DIRS})
# message("Built Checker")

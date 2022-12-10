cmake_minimum_required(VERSION 3.10)

project(namespaces)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_options(${PROJECT_NAME} INTERFACE -lpthread)
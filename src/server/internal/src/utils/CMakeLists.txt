cmake_minimum_required(VERSION 3.10)

project(utils)

set(BOOST_ROOT /usr/include/boost)

find_package(
    Boost
    COMPONENTS
    system
    thread
)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    ${Boost_INCLUDE_DIR}
)

target_link_options(${PROJECT_NAME} INTERFACE -lpthread)
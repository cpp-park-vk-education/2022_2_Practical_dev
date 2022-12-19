cmake_minimum_required(VERSION 3.10)

project(router)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_library(${PROJECT_NAME} ${SOURCES})

target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
    -g
    -Wall
    -Wextra
    -O2
    -pedantic
    -Wformat=2
    -Wfloat-equal
    -Wconversion
    -Wlogical-op
    -Wshift-overflow=2
    -Wduplicated-cond
    -Wcast-qual
    -Wcast-align
)

target_link_libraries(
    ${PROJECT_NAME}
    utils
    contests
)

enable_testing()
add_subdirectory(tests)
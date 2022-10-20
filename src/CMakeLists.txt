cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME "What a contest!")

project(${PROJECT_NAME})

add_subdirectory(db)


message("NumbersCounterLib_LIB = ${NumbersCounterLib_LIB}")
message("NumbersCounterLib_INCLUDE_DIRS = ${NumbersCounterLib_INCLUDE_DIRS}")


# SANITIZE_BUILD - санитайзеры;
set(BUILD_DEV TRUE CACHE BOOL "build dev version")
set(SANITIZE_BUILD TRUE CACHE BOOL "build with sanitizers")

if(BUILD_DEV)
    enable_testing()
    message("Building dev version")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  --coverage -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -g -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion \
        -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align ")
    if(SANITIZE_BUILD)
        message("Sanitizers ON")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fsanitize=address,undefined -fno-sanitize-recover=all -fsanitize-undefined-trap-on-error")
    endif(SANITIZE_BUILD)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov")
endif(BUILD_DEV)

set(BUILD_SERVER "BUILD_SERVER")
set(BUILD_CLIENT "BUILD_CLIENT")
set(BUILD_ALL "BUILD_ALL")

set(BUILD_MODE ${BUILD_SERVER})

if((BUILD_MODE STREQUAL ${BUILD_SERVER}) OR (BUILD_MODE STREQUAL ${BUILD_ALL}))
    add_executable(Server server/main.cpp)
    target_link_libraries(Server PRIVATE ${NumbersCounterLib_LIB})
    target_include_directories(Server PUBLIC ${NumbersCounterLib_INCLUDE_DIRS})
    message("BUILD SERVER")
endif()
if((BUILD_MODE STREQUAL ${BUILD_CLIENT}) OR (BUILD_MODE STREQUAL ${BUILD_ALL}))
    add_executable(Client client/main.cpp)
    target_link_libraries(Client PRIVATE ${NumbersCounterLib_LIB})
    target_include_directories(Client PUBLIC ${NumbersCounterLib_INCLUDE_DIRS})
    message("BUILD CLIENT")
endif()


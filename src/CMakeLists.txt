cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME "What a contest!")

project(${PROJECT_NAME})

# SANITIZE_BUILD - санитайзеры;
set(BUILD_DEV TRUE CACHE BOOL "build dev version")
set(SANITIZE_BUILD TRUE CACHE BOOL "build with sanitizers")

if(BUILD_DEV)
    enable_testing()
    message("Building dev version")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  --coverage -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -g -Wall -Wextra -pedantic -Wformat=2 -Wfloat-equal -Wconversion \
        -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -lpq -lpqxx")
    if(SANITIZE_BUILD)
        message("Sanitizers ON")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fsanitize=address,undefined -fno-sanitize-recover=all -fsanitize-undefined-trap-on-error")
    endif(SANITIZE_BUILD)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov -lpq -lpqxx")
endif(BUILD_DEV)

set(BUILD_SERVER "BUILD_SERVER")
set(BUILD_CLIENT "BUILD_CLIENT")
set(BUILD_ALL "BUILD_ALL")

set(BUILD_MODE ${BUILD_CLIENT})

if((BUILD_MODE STREQUAL ${BUILD_CLIENT}) OR (BUILD_MODE STREQUAL ${BUILD_ALL}))
    add_subdirectory(client)
endif()

if((BUILD_MODE STREQUAL ${BUILD_SERVER}) OR (BUILD_MODE STREQUAL ${BUILD_ALL}))
    # add_subdirectory(server)
endif()

set(TEST_TARGETS db_tests)
set(TARGET_TYPES TEST COVERAGE COVERAGE_FILE VALGRIND)

foreach(TEST_TARGET IN LISTS TEST_TARGETS)
    foreach(TARGET_TYPE IN LISTS TARGET_TYPES)
        list(APPEND TEST_${TARGET_TYPE}_TARGETS ${TEST_TARGET}_${TARGET_TYPE})
    endforeach()
endforeach()

foreach(TARGET_TYPE IN LISTS TARGET_TYPES)
    add_custom_target(
        full_test_${TARGET_TYPE}
        DEPENDS ${TEST_${TARGET_TYPE}_TARGETS}
    )
endforeach()

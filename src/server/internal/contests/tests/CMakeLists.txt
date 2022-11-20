cmake_minimum_required(VERSION 3.10)
project(Contest_tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

if(BUILD_TYPE)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0 -g")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
endif(BUILD_TYPE)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
message("${TEST_SOURCES}")

include(GoogleTest)
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${Contest_Lib_LIB} GTest::gtest_main)
target_include_directories(${PROJECT_NAME} PUBLIC ${Contest_Lib_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC --coverage)
target_link_options(${PROJECT_NAME} PUBLIC --coverage)

gtest_discover_tests(${PROJECT_NAME})

add_custom_target(
  ${PROJECT_NAME}_TEST
  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
)

add_custom_target(
  ${PROJECT_NAME}_COVERAGE
  COMMAND gcovr ${CMAKE_CURRENT_BINARY_DIR} -r ${CMAKE_CURRENT_SOURCE_DIR}
  # DEPENDS ${PROJECT_NAME}_TEST
)

add_custom_target(
  ${PROJECT_NAME}_COVERAGE_FILE
  COMMAND rm -r ${CMAKE_CURRENT_BINARY_DIR}/report || echo "There are no reports"
  COMMAND mkdir ${CMAKE_CURRENT_BINARY_DIR}/report
  COMMAND gcovr ${CMAKE_CURRENT_BINARY_DIR} -r ${CMAKE_CURRENT_SOURCE_DIR} --html-details report/report.html
  # DEPENDS ${PROJECT_NAME}_TEST
)

add_custom_target(
  ${PROJECT_NAME}_VALGRIND
  COMMAND valgrind -s --leak-check=full --show-leak-kinds=all ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
)

FIND_PACKAGE(GTest REQUIRED)
project(gui_tests)
find_package(Qt5 COMPONENTS Widgets REQUIRED)



ADD_EXECUTABLE(
        gui_tests
        src/main.cpp
        src/screensfactory_test.cpp
        src/navigator_test.cpp
)

TARGET_LINK_LIBRARIES(gui_tests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} what_a_contest_gui -lstdc++fs)

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


FIND_PACKAGE(GTest REQUIRED)
FIND_PACKAGE(Threads REQUIRED)

find_package(Qt5 COMPONENTS Widgets REQUIRED)



ADD_EXECUTABLE(
        tests
        src/main.cpp
        src/screensfactory_test.cpp
        src/navigator_test.cpp
)

TARGET_LINK_LIBRARIES(tests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} what_a_contest_gui -lstdc++fs)
SET (TEST_COMMAND ${CMAKE_BINARY_DIR}/project/tests/tests)

ADD_TEST(
        NAME GuiTest
        COMMAND ${TEST_COMMAND}  --gtest_filter=-*Extra*
)

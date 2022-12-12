#include <gtest/gtest.h>

#include "TaskCreatorImpl.hpp"

TEST(TaskCreatorTest, BaseTest) {
    TaskCreatorImpl creator;
    Task task;
    task.setMemoryLimit(100);
    task.setTimeLimit(10);
    task.setId(1);
    RunConfig cxx_conf1, cxx_conf2;
    cxx_conf1.compiler = "g++";
    cxx_conf1.compiler_flags = "-osolution.out";
    cxx_conf1.interpreter = "./";
    cxx_conf1.interpreter_flags = "solution.out";
    cxx_conf2.compiler = "g++";
    cxx_conf2.compiler_flags = "-ogen_test.out";
    cxx_conf2.interpreter = "./";
    cxx_conf2.interpreter_flags = "gen_test.out";
    creator.Setup(task, cxx_conf1, cxx_conf2);
}

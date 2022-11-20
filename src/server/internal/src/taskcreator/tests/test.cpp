#include <gtest/gtest.h>

#include "TaskCreatorImpl.hpp"

TEST(TaskCreatorTest, BaseTest) {
    TaskCreatorImpl creator;
    Task task;
    task.setMemoryLimit(100);
    task.setTimeLimit(std::chrono::seconds(10));
    creator.Setup(task);
}
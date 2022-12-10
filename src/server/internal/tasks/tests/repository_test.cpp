#include <gtest/gtest.h>

#include "TaskRepositoryImpl.hpp"

TEST(TaskRepositoryTest, DISABLED_CRUD) {
    TaskRepositoryImpl repository;
    Task perl_task(1, "count meaning of life", "learning perl basics", 100, 0);

    EXPECT_EQ(repository.Select(perl_task), perl_task);

    perl_task.setTimeLimit(100);

    EXPECT_EQ(repository.Update(perl_task), perl_task);
}

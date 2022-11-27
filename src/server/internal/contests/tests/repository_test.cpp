#include <gtest/gtest.h>

#include "ContestRepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    DBContest repository;
    Contest sorevnovanie(1, "learning perl", "very simple", "");
    Task zadacha(1, "find intelligent life", "It probably exists somewhere in the outer space", 100, 0);

    sorevnovanie.setId(1);
    EXPECT_EQ(repository.Add(sorevnovanie), sorevnovanie);

    EXPECT_EQ(repository.AddTaskIntoContest(sorevnovanie, zadacha), 0);
    EXPECT_EQ(repository.GetTasksByContest(sorevnovanie)[0], zadacha);
    EXPECT_EQ(repository.DeleteTaskFromContest(sorevnovanie, zadacha), 0);

    EXPECT_EQ(repository.Delete(sorevnovanie), 0);
}

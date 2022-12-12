#include <gtest/gtest.h>

#include "ContestRepositoryImpl.hpp"

TEST(ContestRepositoryTest, CRUD) {
    ContestRepositoryImpl repository;
    Contest sorevnovanie(1, "learning perl", "very simple", "");
    std::cout << "here" << std::endl;
    Task zadacha(1, "find intelligent life", "It probably exists somewhere in the outer space", 100, 0);

    sorevnovanie.setId(1);

    Contest new_contest = repository.Add(sorevnovanie);
    EXPECT_EQ(new_contest, sorevnovanie);

    EXPECT_EQ(repository.AddTaskIntoContest(new_contest, zadacha), 0);
    // std::vector<Task> tasks = repository.GetTasksByContest(new_contest);
    // EXPECT_EQ(tasks[0], zadacha);
    EXPECT_EQ(repository.DeleteTaskFromContest(new_contest, zadacha), 404);

    EXPECT_EQ(repository.Delete(new_contest), 0);
}

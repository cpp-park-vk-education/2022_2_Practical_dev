#include <gtest/gtest.h>

#include "RepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    DBUserImpl repository;
    User slava(1, "slava", "slava@slava.ru", "qwerty123");

    EXPECT_EQ(repository.GetById(1), slava);
    EXPECT_EQ(repository.Get(slava), slava);

    EXPECT_EQ(repository.Signup(slava), 10);
    EXPECT_EQ(repository.Signin(slava), 0);

    slava.setNickname("slava123");

    EXPECT_EQ(repository.Update(slava), 0);

    Contest sorevnovanie(1, "learning perl", "very simple", "");

    EXPECT_EQ(repository.AddContest(slava, sorevnovanie), 0);

    EXPECT_EQ(repository.GetContestsByUser(slava)[0], sorevnovanie);

    EXPECT_EQ(repository.DeleteContest(slava, sorevnovanie), 0);
}

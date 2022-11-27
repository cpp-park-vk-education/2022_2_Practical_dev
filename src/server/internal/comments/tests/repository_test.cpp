#include <gtest/gtest.h>

#include "CommentRepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    DBComment repository;
    Comment source(14, 10, "Сап двач, на днях начал изучать перл...");
    Comment source_liked(14, 10, "Сап двач, на днях начал изучать перл...");
    source_liked.setRaiting(-1);

    EXPECT_NO_FATAL_FAILURE(repository.Insert(source));

    EXPECT_EQ(repository.Sage(source), source_liked);

    source_liked.setRaiting(1);
    EXPECT_EQ(repository.Bump(source), source_liked);

    EXPECT_EQ(repository.Update(source), source);
    EXPECT_EQ(repository.Delete(source), 0);
}

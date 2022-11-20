#include <gtest/gtest.h>

#include "RepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    DBContest crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectMany("SELECT * FROM Contests", 10));
    EXPECT_NO_FATAL_FAILURE(crud.Select("SELECT * FROM Contests WHERE id = 1"));

    Contest source;
    source.setName("godnota");
    source.setPassword("12345678");

    EXPECT_NO_FATAL_FAILURE(crud.Insert(source));
    EXPECT_NO_FATAL_FAILURE(crud.Update(source));
    EXPECT_NO_FATAL_FAILURE(crud.Delete(source));
}


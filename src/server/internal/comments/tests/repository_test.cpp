#include <gtest/gtest.h>

#include "RepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    DBComment crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectMany("SELECT * FROM Comments", 10));
    EXPECT_NO_FATAL_FAILURE(crud.Select("SELECT * FROM Comments WHERE id = 1"));

    Comment source;
    source.setText("godnota");
    source.setRaiting(100);

    EXPECT_NO_FATAL_FAILURE(crud.Insert(source));
    EXPECT_NO_FATAL_FAILURE(crud.Update(source));
    EXPECT_NO_FATAL_FAILURE(crud.Delete(source));
}


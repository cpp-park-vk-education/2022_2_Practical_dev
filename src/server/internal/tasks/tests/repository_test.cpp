#include <gtest/gtest.h>

#include "RepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    DBTask crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectMany("SELECT * FROM Tasks", 10));
    EXPECT_NO_FATAL_FAILURE(crud.Select("SELECT * FROM Tasks WHERE id = 1"));

    Task source;
    source.setName("Dada");
    source.setCost(100);

    EXPECT_NO_FATAL_FAILURE(crud.Insert(source));
    EXPECT_NO_FATAL_FAILURE(crud.Update(source));
    EXPECT_NO_FATAL_FAILURE(crud.Delete(source));
}


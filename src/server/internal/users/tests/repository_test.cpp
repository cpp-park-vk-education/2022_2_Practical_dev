#include <gtest/gtest.h>

#include "RepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    DBUser crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectMany("SELECT * FROM Users", 10));
    EXPECT_NO_FATAL_FAILURE(crud.Select("SELECT * FROM Users WHERE id = 1"));

    User source;
    source.setNickname("Dada");
    source.setEmail("georgre4ko@ya.ru");

    EXPECT_NO_FATAL_FAILURE(crud.Insert(source));
    EXPECT_NO_FATAL_FAILURE(crud.Update(source));
    EXPECT_NO_FATAL_FAILURE(crud.Delete(source));
}


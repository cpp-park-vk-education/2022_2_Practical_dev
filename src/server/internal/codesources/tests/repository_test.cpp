#include <gtest/gtest.h>

#include "CodeSourceRepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    CodeSourceRepositoryImpl crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectMany("SELECT * FROM CodeSources", 10));
    EXPECT_NO_FATAL_FAILURE(crud.Select("SELECT * FROM CodeSources WHERE id = 1"));

    CodeSource source;
    source.setRunConfig(10);
    source.setSource("print(\"test\"");

    EXPECT_NO_FATAL_FAILURE(crud.Insert(source));
    EXPECT_NO_FATAL_FAILURE(crud.Update(source));
    EXPECT_NO_FATAL_FAILURE(crud.Delete(source));
}


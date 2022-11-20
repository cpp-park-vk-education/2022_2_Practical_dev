#include <gtest/gtest.h>

#include "RepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    DBRunConfig crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectMany("SELECT * FROM RunConfigs", 10));
    EXPECT_NO_FATAL_FAILURE(crud.Select("SELECT * FROM RunConfigs WHERE id = 1"));

    RunConfig source;
    source.setName("Dada");
    source.setCompiler("c++");

    EXPECT_NO_FATAL_FAILURE(crud.Insert(source));
    EXPECT_NO_FATAL_FAILURE(crud.Update(source));
    EXPECT_NO_FATAL_FAILURE(crud.Delete(source));
}


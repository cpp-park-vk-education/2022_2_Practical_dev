#include <gtest/gtest.h>

#include "RunConfigRepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    DBRunConfigImpl crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectMany("SELECT * FROM RunConfigs", 10));
    EXPECT_NO_FATAL_FAILURE(crud.Select("SELECT * FROM RunConfigs WHERE id = 1"));

    RunConfig source;
    source.name = "Dada";
    source.compiler = "c++";

    EXPECT_NO_FATAL_FAILURE(crud.Insert(source));
    EXPECT_NO_FATAL_FAILURE(crud.Update(source));
    EXPECT_NO_FATAL_FAILURE(crud.Delete(source));
}


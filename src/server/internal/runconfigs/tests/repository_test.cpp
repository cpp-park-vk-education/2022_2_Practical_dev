#include <gtest/gtest.h>

#include "RunConfigRepositoryImpl.hpp"

TEST(RunConfigRepositoryTest, CRUD) {
    RunConfigRepositoryImpl crud;

    // EXPECT_NO_FATAL_FAILURE(crud.SelectMany("SELECT * FROM RunConfigs", 10));
    // EXPECT_NO_FATAL_FAILURE(crud.Select("SELECT * FROM RunConfigs WHERE id = 1"));

    RunConfig source;
    source.name = "c++ 17";
    source.compiler = "g++";
    source.compiler_flags = "--std=c++17";
    source.interpreter = "/.";
    source.interpreter_flags = " ";

    RunConfig new_source = crud.Insert(source);
    EXPECT_EQ(new_source, source);
    new_source.compiler_flags = "--std=c++17 -O0";
    EXPECT_NO_FATAL_FAILURE(crud.Update(new_source));
    EXPECT_EQ(new_source, crud.SelectById(new_source.id));
    EXPECT_EQ(new_source, crud.SelectByName(new_source.name));
    EXPECT_NO_FATAL_FAILURE(crud.Delete(new_source));
}

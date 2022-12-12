#include <gtest/gtest.h>

#include "CodeSourceRepositoryImpl.hpp"

TEST(CodeSourceRepositoryTest, CRUD) {
    CodeSourceRepositoryImpl crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectById(1));

    CodeSource source;
    source.setRunConfig(10);
    source.setSource("print(\"test\"");

    CodeSource new_source = crud.Insert(source);
    EXPECT_EQ(new_source, source);

    new_source.setSource("print(\"test\" + 1");
    EXPECT_EQ(crud.Update(new_source), 0);

    EXPECT_EQ(crud.Delete(new_source), 0);
}

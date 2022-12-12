#include <gtest/gtest.h>

#include "ParcelRepositoryImpl.hpp"

TEST(ParcelRepositoryTest, CRUD) {
    ParcelRepositoryImpl crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectById(1));

    Parcel source(1, 4, 10, "OK");
    source.setPoints(1000);
    source.setRunMemory(0.01);
    source.setFailedTest(0);

    Parcel new_source = crud.Insert(source);
    EXPECT_EQ(source, new_source);

    new_source.setFailedTest(10);
    EXPECT_NO_FATAL_FAILURE(crud.Update(new_source));

    EXPECT_NO_FATAL_FAILURE(crud.Delete(new_source));
}

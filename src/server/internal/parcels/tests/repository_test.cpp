#include <gtest/gtest.h>

#include "ParcelRepositoryImpl.hpp"

TEST(RepositoryTest, CRUD) {
    ParcelRepositoryImpl crud;

    EXPECT_NO_FATAL_FAILURE(crud.SelectMany("SELECT * FROM Parcels", 10));
    EXPECT_NO_FATAL_FAILURE(crud.Select("SELECT * FROM Parcels WHERE id = 1"));

    Parcel source;
    source.setPoints(1000);
    source.setRunMemory(0.01);

    EXPECT_NO_FATAL_FAILURE(crud.Insert(source));
    EXPECT_NO_FATAL_FAILURE(crud.Update(source));
    EXPECT_NO_FATAL_FAILURE(crud.Delete(source));
}


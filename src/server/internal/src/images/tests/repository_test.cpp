#include <gtest/gtest.h>

#include "ImageRepositoryImpl.hpp"

TEST(ImageRepository, CRUD) {
    ImageRepositoryImpl crud;
    EXPECT_NO_FATAL_FAILURE(crud.SelectById(1));

    Image image(10, "0800f7ed72b6");

    Image new_image = crud.Insert(image);
    EXPECT_EQ(image, new_image);

    new_image.setTaskId(11);

    EXPECT_EQ(crud.Update(new_image), 0);
    EXPECT_EQ(crud.Delete(new_image), 0);
}

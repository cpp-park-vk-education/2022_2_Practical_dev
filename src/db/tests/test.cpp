#include <gtest/gtest.h>

#include <db.hpp>
#include <sstream>

TEST(DB, BaseTest) {
    EXPECT_EQ(foo(), 10);
}

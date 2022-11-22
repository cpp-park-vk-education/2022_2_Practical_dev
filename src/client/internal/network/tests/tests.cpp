#include <gtest/gtest.h>

#include <Contest.hpp>
#include <User.hpp>


class contestTest: public testing::Test {
 public:
    Contest* contestForTest = new Contest;
    Data data = {
        2022, 11, 21, 22, 10,
    };
    void SetUp() {
        contestForTest->setUuid(15);
        contestForTest->setIdContest(30);
        contestForTest->setName("avl tree");
        contestForTest->setDescription("different tree and a lot of love");
        contestForTest->setContainer("Python3.9");
    }

    void TearDown() {
        delete contestForTest;
    }
};

TEST_F(contestTest, getUuid) {
    size_t value = contestForTest->getUuid();
    EXPECT_EQ(value, 15);
}

TEST_F(contestTest, getId) {
    size_t value = contestForTest->getIdContest();
    EXPECT_EQ(value, 30);
}

TEST_F(contestTest, getName) {
    std::string value = contestForTest->getName();
    EXPECT_EQ(value, "avl tree");
}

TEST_F(contestTest, getDescription) {
    std::string value = contestForTest->getDescription();
    EXPECT_EQ(value, "different tree and a lot of love");

    std::cout << value << std::endl;
}

TEST_F(contestTest, getStartTime) {  // TODO:: == for Data structure
    GTEST_SKIP();
    Data value = contestForTest->getStartTime();
    // EXPECT_EQ();
}

TEST_F(contestTest, getEndTime) {
    GTEST_SKIP();
    Data value = contestForTest->getEndTime();
    // EXPECT_EQ(value, );
}


class userTest: public testing::Test {
public:
    User* userForTest = new User;
    void SetUp() {
        userForTest->setId(20);
        userForTest->setNickname("Slava");
        userForTest->setEmail("slava@mail.ru");
    }

    void TearDown() {
        delete userForTest;
    }
};

TEST_F(userTest, getId) {
    size_t value = userForTest->getId();
    EXPECT_EQ(value, 20);
}

TEST_F(userTest, getNickname) {
    std::string value = userForTest->getNickname();
    EXPECT_EQ(value, "Slava");
}

TEST_F(userTest, getEmail) {
    std::string value = userForTest->getEmail();
    EXPECT_EQ(value, "slava@mail.ru");
}
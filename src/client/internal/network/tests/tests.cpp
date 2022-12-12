#include <gtest/gtest.h>

#include <Contest.hpp>
#include <ImplContestAPI.hpp>
#include <ImplParcelAPI.hpp>
#include <ImplTaskAPI.hpp>
#include <ImplUserAPI.hpp>
#include <Parcel.hpp>
#include <Task.hpp>
#include <User.hpp>

class contestTest : public testing::Test {
 public:
    Contest* contestForTest = new Contest;
    Data data = {
        2022,
        11,
        21,
        22,
        10,
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

TEST_F(contestTest, DISABLED_getUuid) {
    size_t value = contestForTest->getUuid();
    EXPECT_EQ(value, 15);
}

TEST_F(contestTest, DISABLED_getId) {
    size_t value = contestForTest->getIdContest();
    EXPECT_EQ(value, 30);
}

TEST_F(contestTest, DISABLED_getName) {
    std::string value = contestForTest->getName();
    EXPECT_EQ(value, "avl tree");
}

TEST_F(contestTest, DISABLED_getDescription) {
    std::string value = contestForTest->getDescription();
    EXPECT_EQ(value, "different tree and a lot of love");
}

TEST_F(contestTest, DISABLED_getStartTime) {  // TODO(data): For Data structure
    GTEST_SKIP();
    // Data value = contestForTest->getStartTime();
    // EXPECT_EQ();
}

TEST_F(contestTest, DISABLED_getEndTime) {
    GTEST_SKIP();
    // Data value = contestForTest->getEndTime();
    // EXPECT_EQ(value, );
}

TEST_F(contestTest, DISABLED_setUuid) {
    contestForTest->setUuid(20);
    size_t value = contestForTest->getUuid();
    EXPECT_EQ(value, 20);
}

TEST_F(contestTest, DISABLED_setId) {
    contestForTest->setIdContest(35);
    size_t value = contestForTest->getIdContest();
    EXPECT_EQ(value, 35);
}

TEST_F(contestTest, DISABLED_setName) {
    contestForTest->setName("bin tree");
    std::string value = contestForTest->getName();
    EXPECT_EQ(value, "bin tree");
}

TEST_F(contestTest, DISABLED_setDescription) {
    contestForTest->setDescription("new different tree and a lot of love");
    std::string value = contestForTest->getDescription();
    EXPECT_EQ(value, "new different tree and a lot of love");
}

TEST_F(contestTest, DISABLED_setStartTime) {  // TODO(data): For Data structure
    GTEST_SKIP();
    // Data value = contestForTest->getStartTime();
    // EXPECT_EQ();
}

TEST_F(contestTest, DISABLED_setEndTime) {
    GTEST_SKIP();
    // Data value = contestForTest->getEndTime();
    // EXPECT_EQ(value, );
}

class userTest : public testing::Test {
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

TEST_F(userTest, DISABLED_getId) {
    size_t value = userForTest->getId();
    EXPECT_EQ(value, 20);
}

TEST_F(userTest, DISABLED_getNickname) {
    std::string value = userForTest->getNickname();
    EXPECT_EQ(value, "Slava");
}

TEST_F(userTest, DISABLED_getEmail) {
    std::string value = userForTest->getEmail();
    EXPECT_EQ(value, "slava@mail.ru");
}

TEST_F(userTest, DISABLED_setId) {
    userForTest->setId(30);
    size_t value = userForTest->getId();
    EXPECT_EQ(value, 30);
}

TEST_F(userTest, DISABLED_setNickname) {
    userForTest->setNickname("Gosha");
    std::string value = userForTest->getNickname();
    EXPECT_EQ(value, "Gosha");
}

TEST_F(userTest, DISABLED_setEmail) {
    userForTest->setEmail("gosha@mail.ru");
    std::string value = userForTest->getEmail();
    EXPECT_EQ(value, "gosha@mail.ru");
}

class taskTest : public testing::Test {
 public:
    Task* taskForTest = new Task;
    void SetUp() {
        taskForTest->setId(20);
        taskForTest->setIdContest(30);
        taskForTest->setDescription("old task, you can solve it");
        taskForTest->setName("taska");
        taskForTest->setContainer("C++");
        taskForTest->setCost(3);
    }

    void TearDown() {
        delete taskForTest;
    }
};

TEST_F(taskTest, DISABLED_getId) {
    size_t value = taskForTest->getId();
    EXPECT_EQ(value, 20);
}

TEST_F(taskTest, DISABLED_getIdContest) {
    size_t value = taskForTest->getIdContest();
    EXPECT_EQ(value, 30);
}

TEST_F(taskTest, DISABLED_getDescription) {
    std::string value = taskForTest->getDescription();
    EXPECT_EQ(value, "old task, you can solve it");
}

TEST_F(taskTest, DISABLED_getName) {
    std::string value = taskForTest->getName();
    EXPECT_EQ(value, "taska");
}

TEST_F(taskTest, DISABLED_getContainer) {
    std::string value = taskForTest->getContainer();
    EXPECT_EQ(value, "C++");
}

TEST_F(taskTest, DISABLED_getCost) {
    int value = taskForTest->getCost();
    EXPECT_EQ(value, 3);
}

TEST_F(taskTest, DISABLED_setId) {
    taskForTest->setId(30);
    size_t value = taskForTest->getId();
    EXPECT_EQ(value, 30);
}

TEST_F(taskTest, DISABLED_setIdContest) {
    taskForTest->setIdContest(25);
    size_t value = taskForTest->getIdContest();
    EXPECT_EQ(value, 25);
}

TEST_F(taskTest, DISABLED_setDescription) {
    taskForTest->setDescription("new task, you can solve it");
    std::string value = taskForTest->getDescription();
    EXPECT_EQ(value, "new task, you can solve it");
}

TEST_F(taskTest, DISABLED_setName) {
    taskForTest->setName("new taska");
    std::string value = taskForTest->getName();
    EXPECT_EQ(value, "new taska");
}

TEST_F(taskTest, DISABLED_setContainer) {
    taskForTest->setContainer("C++ 17");
    std::string value = taskForTest->getContainer();
    EXPECT_EQ(value, "C++ 17");
}

TEST_F(taskTest, DISABLED_setCost) {
    taskForTest->setCost(19);
    int value = taskForTest->getCost();
    EXPECT_EQ(value, 19);
}

class parcelTest : public testing::Test {
 public:
    Parcel* parcelForTest = new Parcel;
    void SetUp() {
        parcelForTest->setId(20);
        parcelForTest->setUserId(35);
        parcelForTest->setTaskId(63);
        parcelForTest->setResult("OK");
        parcelForTest->setIsBest(true);
        parcelForTest->setRunningMemory(0.63);
        parcelForTest->setFailedTest(0);
        parcelForTest->setPoints(15);
    }

    void TearDown() {
        delete parcelForTest;
    }
};

TEST_F(parcelTest, DISABLED_getId) {
    size_t value = parcelForTest->getId();
    EXPECT_EQ(value, 20);
}

TEST_F(parcelTest, DISABLED_getUserId) {
    size_t value = parcelForTest->getUserId();
    EXPECT_EQ(value, 35);
}

TEST_F(parcelTest, DISABLED_getTaskId) {
    size_t value = parcelForTest->getTaskId();
    EXPECT_EQ(value, 63);
}

TEST_F(parcelTest, DISABLED_getResult) {
    std::string value = parcelForTest->getResult();
    EXPECT_EQ(value, "OK");
}

TEST_F(parcelTest, DISABLED_getIsBest) {
    bool value = parcelForTest->getIsBest();
    EXPECT_EQ(value, true);
}

TEST_F(parcelTest, DISABLED_getRunningMemory) {
    float value = parcelForTest->getRunningMemory();
    EXPECT_FLOAT_EQ(value, 0.63);
}

TEST_F(parcelTest, DISABLED_getFailedTest) {
    size_t value = parcelForTest->getFailedTest();
    EXPECT_EQ(value, 0);
}

TEST_F(parcelTest, DISABLED_getPoints) {
    int value = parcelForTest->getPoints();
    EXPECT_EQ(value, 15);
}

TEST_F(parcelTest, DISABLED_setId) {
    parcelForTest->setId(30);
    size_t value = parcelForTest->getId();
    EXPECT_EQ(value, 30);
}

TEST_F(parcelTest, DISABLED_setUserId) {
    parcelForTest->setUserId(45);
    size_t value = parcelForTest->getUserId();
    EXPECT_EQ(value, 45);
}

TEST_F(parcelTest, DISABLED_setTaskId) {
    parcelForTest->setTaskId(68);
    size_t value = parcelForTest->getTaskId();
    EXPECT_EQ(value, 68);
}

TEST_F(parcelTest, DISABLED_setResult) {
    parcelForTest->setResult("TL");
    std::string value = parcelForTest->getResult();
    EXPECT_EQ(value, "TL");
}

TEST_F(parcelTest, DISABLED_setIsBest) {
    parcelForTest->setIsBest(false);
    bool value = parcelForTest->getIsBest();
    EXPECT_EQ(value, false);
}

TEST_F(parcelTest, DISABLED_setRunningMemory) {
    parcelForTest->setRunningMemory(1.56);
    float value = parcelForTest->getRunningMemory();
    EXPECT_FLOAT_EQ(value, 1.56);
}

TEST_F(parcelTest, DISABLED_setFailedTest) {
    parcelForTest->setFailedTest(10);
    size_t value = parcelForTest->getFailedTest();
    EXPECT_EQ(value, 10);
}

TEST_F(parcelTest, DISABLED_setPoints) {
    parcelForTest->setPoints(11);
    int value = parcelForTest->getPoints();
    EXPECT_EQ(value, 11);
}

TEST(User, DISABLED_constructUserAPI) {
    // ImplUserAPI* userAPI;
}

TEST(Contest, DISABLED_constructContestAPI) {
    // ImplContestAPI* contestAPI;
}

TEST(Task, DISABLED_constructTaskAPI) {
    // ImplTaskAPI* taskAPI;
}

TEST(Parcel, DISABLED_constructParcelAPI) {
    // ImplParcelAPI* parcelAPI;
}

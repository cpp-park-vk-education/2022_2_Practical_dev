#include <gtest/gtest.h>

#include <Contest.hpp>
#include <User.hpp>
#include <Task.hpp>
#include <Parcel.hpp>

#include <ImplUserAPI.hpp>
#include <ImplContestAPI.hpp>
#include <ImplTaskAPI.hpp>
#include <ImplParcelAPI.hpp>


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
}

TEST_F(contestTest, getStartTime) {  // TODO(data): For Data structure
    GTEST_SKIP();
    Data value = contestForTest->getStartTime();
    // EXPECT_EQ();
}

TEST_F(contestTest, getEndTime) {
    GTEST_SKIP();
    Data value = contestForTest->getEndTime();
    // EXPECT_EQ(value, );
}

TEST_F(contestTest, setUuid) {
    contestForTest->setUuid(20);
    size_t value = contestForTest->getUuid();
    EXPECT_EQ(value, 20);
}

TEST_F(contestTest, setId) {
    contestForTest->setIdContest(35);
    size_t value = contestForTest->getIdContest();
    EXPECT_EQ(value, 35);
}

TEST_F(contestTest, setName) {
    contestForTest->setName("bin tree");
    std::string value = contestForTest->getName();
    EXPECT_EQ(value, "bin tree");
}

TEST_F(contestTest, setDescription) {
    contestForTest->setDescription("new different tree and a lot of love");
    std::string value = contestForTest->getDescription();
    EXPECT_EQ(value, "new different tree and a lot of love");
}

TEST_F(contestTest, setStartTime) {  // TODO(data): For Data structure
    GTEST_SKIP();
    Data value = contestForTest->getStartTime();
    // EXPECT_EQ();
}

TEST_F(contestTest, setEndTime) {
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

TEST_F(userTest, setId) {
    userForTest->setId(30);
    size_t value = userForTest->getId();
    EXPECT_EQ(value, 30);
}

TEST_F(userTest, setNickname) {
    userForTest->setNickname("Gosha");
    std::string value = userForTest->getNickname();
    EXPECT_EQ(value, "Gosha");
}

TEST_F(userTest, setEmail) {
    userForTest->setEmail("gosha@mail.ru");
    std::string value = userForTest->getEmail();
    EXPECT_EQ(value, "gosha@mail.ru");
}

class taskTest: public testing::Test {
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

TEST_F(taskTest, getId) {
    size_t value = taskForTest->getId();
    EXPECT_EQ(value, 20);
}

TEST_F(taskTest, getIdContest) {
    size_t value = taskForTest->getIdContest();
    EXPECT_EQ(value, 30);
}

TEST_F(taskTest, getDescription) {
    std::string value = taskForTest->getDescription();
    EXPECT_EQ(value, "old task, you can solve it");
}

TEST_F(taskTest, getName) {
    std::string value = taskForTest->getName();
    EXPECT_EQ(value, "taska");
}

TEST_F(taskTest, getContainer) {
    std::string value = taskForTest->getContainer();
    EXPECT_EQ(value, "C++");
}

TEST_F(taskTest, getCost) {
    int value = taskForTest->getCost();
    EXPECT_EQ(value, 3);
}

TEST_F(taskTest, setId) {
    taskForTest->setId(30);
    size_t value = taskForTest->getId();
    EXPECT_EQ(value, 30);
}

TEST_F(taskTest, setIdContest) {
    taskForTest->setIdContest(25);
    size_t value = taskForTest->getIdContest();
    EXPECT_EQ(value, 25);
}

TEST_F(taskTest, setDescription) {
    taskForTest->setDescription("new task, you can solve it");
    std::string value = taskForTest->getDescription();
    EXPECT_EQ(value, "new task, you can solve it");
}

TEST_F(taskTest, setName) {
    taskForTest->setName("new taska");
    std::string value = taskForTest->getName();
    EXPECT_EQ(value, "new taska");
}

TEST_F(taskTest, setContainer) {
    taskForTest->setContainer("C++ 17");
    std::string value = taskForTest->getContainer();
    EXPECT_EQ(value, "C++ 17");
}

TEST_F(taskTest, setCost) {
    taskForTest->setCost(19);
    int value = taskForTest->getCost();
    EXPECT_EQ(value, 19);
}

class parcelTest: public testing::Test {
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

TEST_F(parcelTest, getId) {
    size_t value = parcelForTest->getId();
    EXPECT_EQ(value, 20);
}

TEST_F(parcelTest, getUserId) {
    size_t value = parcelForTest->getUserId();
    EXPECT_EQ(value, 35);
}

TEST_F(parcelTest, getTaskId) {
    size_t value = parcelForTest->getTaskId();
    EXPECT_EQ(value, 63);
}

TEST_F(parcelTest, getResult) {
    std::string value = parcelForTest->getResult();
    EXPECT_EQ(value, "OK");
}

TEST_F(parcelTest, getIsBest) {
    bool value = parcelForTest->getIsBest();
    EXPECT_EQ(value, true);
}

TEST_F(parcelTest, getRunningMemory) {
    float value = parcelForTest->getRunningMemory();
    EXPECT_FLOAT_EQ(value, 0.63);
}

TEST_F(parcelTest, getFailedTest) {
    size_t value = parcelForTest->getFailedTest();
    EXPECT_EQ(value, 0);
}

TEST_F(parcelTest, getPoints) {
    int value = parcelForTest->getPoints();
    EXPECT_EQ(value, 15);
}

TEST_F(parcelTest, setId) {
    parcelForTest->setId(30);
    size_t value = parcelForTest->getId();
    EXPECT_EQ(value, 30);
}

TEST_F(parcelTest, setUserId) {
    parcelForTest->setUserId(45);
    size_t value = parcelForTest->getUserId();
    EXPECT_EQ(value, 45);
}

TEST_F(parcelTest, setTaskId) {
    parcelForTest->setTaskId(68);
    size_t value = parcelForTest->getTaskId();
    EXPECT_EQ(value, 68);
}

TEST_F(parcelTest, setResult) {
    parcelForTest->setResult("TL");
    std::string value = parcelForTest->getResult();
    EXPECT_EQ(value, "TL");
}

TEST_F(parcelTest, setIsBest) {
    parcelForTest->setIsBest(false);
    bool value = parcelForTest->getIsBest();
    EXPECT_EQ(value, false);
}

TEST_F(parcelTest, setRunningMemory) {
    parcelForTest->setRunningMemory(1.56);
    float value = parcelForTest->getRunningMemory();
    EXPECT_FLOAT_EQ(value, 1.56);
}

TEST_F(parcelTest, setFailedTest) {
    parcelForTest->setFailedTest(10);
    size_t value = parcelForTest->getFailedTest();
    EXPECT_EQ(value, 10);
}

TEST_F(parcelTest, setPoints) {
    parcelForTest->setPoints(11);
    int value = parcelForTest->getPoints();
    EXPECT_EQ(value, 11);
}

TEST(User, constructUserAPI) {
    ImplUserAPI* userAPI = new ImplUserAPI;
}

TEST(Contest, constructContestAPI) {
    ImplContestAPI* contestAPI = new ImplContestAPI;
}

TEST(Task, constructTaskAPI) {
    ImplTaskAPI* taskAPI = new ImplTaskAPI;
}

TEST(Parcel, constructParcelAPI) {
    ImplParcelAPI* parcelAPI = new ImplParcelAPI;
}



#include <gtest/gtest.h>

#include "User.hpp"

TEST(UserModel, BaseTest) {
    User user;
    user.setEmail("georgre4ko@ya.ru");
    user.setPassword("12345678", "12345678");
    user.setNickname("georgre4ko");

    EXPECT_EQ(user.getEmail(), "georgre4ko@ya.ru");
    EXPECT_EQ(user.getPassword(), "12345678");
    EXPECT_EQ(user.getNickname(), "georgre4ko");
}

#include "Task.hpp"

TEST(TaskModel, BaseTest) {
    Task task;

    task.setName("ZADACHA");
    task.setCost(100);
    task.setMemoryLimit(1000);
    task.setDescription("It is very hard");

    EXPECT_EQ(task.getName(), "ZADACHA");
    EXPECT_EQ(task.getCost(), 100);
    EXPECT_EQ(task.getMemoryLimit(), 1000);
    EXPECT_EQ(task.getDescription(), "It is very hard");
}

#include "RunConfig.hpp"

TEST(RunConfigModel, BaseTest) {
    RunConfig cfg;

    cfg.compiler = "g++";
    cfg.compiler_flags = "--std=c++17 -Wall";
    cfg.interpreter = "./";
    cfg.name = "C++ 17 standart";

    EXPECT_EQ(cfg.compiler, "g++");
    EXPECT_EQ(cfg.name, "C++ 17 standart");
}

#include "Parcel.hpp"

TEST(ParcelModel, BaseTest) {
    Parcel parcel;

    parcel.setPoints(100);
    parcel.setResult("OK");
    parcel.setRunMemory(0.01);

    EXPECT_EQ(parcel.getPoints(), 100);
    EXPECT_EQ(parcel.getResult(), "OK");
    EXPECT_FLOAT_EQ(parcel.getRunMemory(), 0.01);
}

#include "Contest.hpp"

TEST(ContestModel, BaseTest) {
    Contest contest;

    contest.setDescription("ХОРОШИЙ КОНТЕСТ");
    contest.setPassword("12345678");

    EXPECT_EQ(contest.getPassword(), "12345678");
    EXPECT_EQ(contest.getDescription(), "ХОРОШИЙ КОНТЕСТ");
}

#include "CodeSource.hpp"

TEST(CodeSourceModel, BaseTest) {
    CodeSource src;

    src.setRunConfig(10);
    src.setSource("print \"test\"");

    EXPECT_EQ(src.getRunConfig(), 10);
    EXPECT_EQ(src.getSource(), "print \"test\"");
}

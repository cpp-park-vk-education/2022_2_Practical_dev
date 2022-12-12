#include <gtest/gtest.h>

#include <screensfactory.hpp>

TEST(ScreensFactoryTest, creationTest) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    delete s;
}

TEST(ScreensFactoryTest, DISABLED_getStartTest) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    ASSERT_EQ(s->getStart(), Screens::SIGNIN_TAG);
    delete s;
}

TEST(ScreensFactoryTest, signinCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(s->getStart());
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, registerCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::REGISTER_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, mainCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::MAIN_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, taskCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::TASK_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, configCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::CONTEST_CONFIGURATION_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, contestCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::CONTEST_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, discussCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::DISCUSS_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

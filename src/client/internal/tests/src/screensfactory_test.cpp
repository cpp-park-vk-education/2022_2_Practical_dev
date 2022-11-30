#include <gtest/gtest.h>

#include <screensfactory.hpp>

TEST(ScreensFactoryTest, DISABLED_creationTest) {
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

TEST(ScreensFactoryTest, DISABLED_signinCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(s->getStart());
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, DISABLED_registerCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::REGISTER_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, DISABLED_mainCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::MAIN_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, DISABLED_taskCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::TASK_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, DISABLED_configCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::CONTEST_CONFIGURATION_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, DISABLED_contestCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::CONTEST_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

TEST(ScreensFactoryTest, DISABLED_discussCreation) {
    ScreensFactory* s = new ScreensFactory();
    ASSERT_TRUE(s);
    BaseFragment* f = s->create(Screens::DISCUSS_TAG);
    ASSERT_TRUE(f);
    delete s;
    delete f;
}

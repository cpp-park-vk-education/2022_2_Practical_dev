#include <gtest/gtest.h>

#include <QStackedWidget>
#include <navigator.hpp>

TEST(NavigatorTest, DISABLED_creation) {
    QStackedWidget* container = new QStackedWidget();
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, DISABLED_startCreation) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    BaseFragment* b = n->getStartScreen();
    delete n;
    ASSERT_TRUE(b);
    delete b;
    delete container;
    delete factory;
}

TEST(NavigatorTest, DISABLED_emptyNavigator) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    ASSERT_EQ(n->getActiveScreensCount(), 0);
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, DISABLED_addFragment) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    n->navigateTo(Screens::SIGNIN_TAG);
    ASSERT_EQ(n->getActiveScreensCount(), 1);
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, DISABLED_backFragment) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    n->navigateTo(Screens::SIGNIN_TAG);
    n->navigateTo(Screens::DISCUSS_TAG);
    n->back();
    ASSERT_EQ(n->getActiveScreensCount(), 1);
    delete container;
    delete factory;
    delete n;
}

TEST(NavigatorTest, DISABLED_navigateToTest) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    n->navigateTo(Screens::CONTEST_TAG);
    ASSERT_EQ(n->getActiveScreensCount(), 1);
    delete container;
    delete factory;
    delete n;
}

TEST(NavigatorTest, DISABLED_emptyBack) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    ASSERT_NO_THROW(n->back());
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, DISABLED_emptyReplace) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    ASSERT_NO_THROW(n->replace(Screens::CONTEST_TAG));
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, DISABLED_overflowTest) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    for (size_t i = 0; i < 10; ++i) {
        n->navigateTo(Screens::MAIN_TAG);
    }
    ASSERT_EQ(2, n->getActiveScreensCount());
    delete container;
    delete factory;
}

TEST(NavigatorTest, DISABLED_replaceTest) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    ASSERT_NO_THROW(n->navigateTo(Screens::MAIN_TAG));
    BaseFragment* tmp = n->getActiveScreen();
    ASSERT_NO_THROW(n->replace(Screens::CONTEST_TAG));
    ASSERT_NE(tmp, n->getActiveScreen());
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, DISABLED_newRootEmptyTest) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    n->newRootScreen(Screens::SIGNIN_TAG);
    ASSERT_EQ(n->getActiveScreensCount(), 1);
    delete container;
    delete factory;
    delete n;
}

TEST(NavigatorTest, DISABLED_newRootTest) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    n->navigateTo(Screens::CONTEST_TAG);
    n->navigateTo(Screens::CONTEST_TAG);
    n->navigateTo(Screens::CONTEST_TAG);
    n->navigateTo(Screens::CONTEST_TAG);
    n->newRootScreen(Screens::SIGNIN_TAG);
    ASSERT_EQ(n->getActiveScreensCount(), 1);
    delete container;
    delete factory;
}

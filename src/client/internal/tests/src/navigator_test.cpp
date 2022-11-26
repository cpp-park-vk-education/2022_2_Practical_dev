#include <gtest/gtest.h>

#include <QStackedWidget>
#include <navigator.hpp>

TEST(NavigatorTest, creation) {
    QStackedWidget* container = new QStackedWidget();
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, startCreation) {
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

TEST(NavigatorTest, emptyNavigator) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    ASSERT_EQ(n->getActiveScreensCount(), 0);
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, addFragment) {
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

TEST(NavigatorTest, backFragment) {
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

TEST(NavigatorTest, navigateToTest) {
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

TEST(NavigatorTest, emptyBack) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    ASSERT_NO_THROW(n->back());
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, emptyReplace) {
    QStackedWidget* container = new QStackedWidget;
    ScreensFactory* factory = new ScreensFactory;
    Navigator* n = new Navigator(container, factory);
    ASSERT_TRUE(n);
    ASSERT_NO_THROW(n->replace(Screens::CONTEST_TAG));
    delete n;
    delete container;
    delete factory;
}

TEST(NavigatorTest, overflowTest) {
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

TEST(NavigatorTest, replaceTest) {
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

TEST(NavigatorTest, newRootEmptyTest) {
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

TEST(NavigatorTest, newRootTest) {
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

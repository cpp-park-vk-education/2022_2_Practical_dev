#pragma once  // NOLINT
#include <QObject>
#include <QStackedWidget>
#include <deque>

#include "basefragment.hpp"
#include "screensfactory.hpp"

class Navigator : public QObject {
    Q_OBJECT

 public:
    BaseFragment* getStartScreen() { return nullptr; }
    ~Navigator() = default;
    Navigator(QStackedWidget* _container, ScreensFactory* _factory): container(_container), factory(_factory) {}
    size_t getActiveScreensCount() { return 0; }
    BaseFragment* getActiveScreen() { return nullptr; }

 private:
    QStackedWidget* container;
    ScreensFactory* factory;
    std::deque<BaseFragment*> deque;
    BaseFragment* createAndConnect();
    void connectFragment(BaseFragment* fragment) {}
    void disconnectFragment(BaseFragment* fragment) {}
 public slots:
    void replace(QString tag) {}
    void navigateTo(QString tag) {}
    void back() {}
    void newRootScreen(QString tag) {}
};

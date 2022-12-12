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
    Navigator(QStackedWidget* _container, ScreensFactory* _factory);
    size_t getActiveScreensCount() { return deque.size(); }
    BaseFragment* getActiveScreen() { return deque.back(); }

 private:
    QStackedWidget* container;
    ScreensFactory* factory;
    std::deque<BaseFragment*> deque;
    BaseFragment* createAndConnect(QString tag);
    BaseFragment* createStart();
    void connectFragment(BaseFragment* fragment);
    void disconnectFragment(BaseFragment* fragment);
 public slots:
    void replace(QString tag) {}
    void navigateTo(QString tag);
    void back() {}
    void newRootScreen(QString tag) {}
};

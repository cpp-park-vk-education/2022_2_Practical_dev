#pragma once  // NOLINT
#include <QObject>
#include <QStackedWidget>
#include <stack>

#include "basefragment.hpp"
#include "screensfactory.hpp"

class Navigator : public QObject {
    Q_OBJECT

 public:
    BaseFragment* getStartScreen();
    Navigator(QStackedWidget* container, ScreensFactory* factory);
    ~Navigator();

 private:
    QStackedWidget* container;
    ScreensFactory* factory;
    std::stack<BaseFragment*> stack;
    BaseFragment* createAndConnect();
    void connectFragment(BaseFragment* fragment);
    void disconnectFragment(BaseFragment* fragment);

 public slots:
    void replace(QString tag);
    void navigateTo(QString tag);
    void back();
    void newRootScreen(QString tag);
};

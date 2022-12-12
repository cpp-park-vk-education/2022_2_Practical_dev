#pragma once  // NOLINT

#include <QFrame>
#include <QPainter>
#include <QStyleOption>

class BaseFragment : public QFrame {
    Q_OBJECT

 private:
    void paintEvent(QPaintEvent *);

 signals:
    void back();
    void navigateTo(QString tag);
    void newRootScreen(QString tag);
    void replace(QString tag);

 public:
    BaseFragment() {}
    ~BaseFragment() {}
};

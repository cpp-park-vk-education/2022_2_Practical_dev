#pragma once  // NOLINT

#include <QFrame>

class BaseFragment : public QFrame {
    Q_OBJECT

 signals:
    void back();
    void navigateTo(QString tag);
    void newRootScreen(QString tag);
    void replace(QString tag);

 public:
    BaseFragment();
    ~BaseFragment() {}
};

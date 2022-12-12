#pragma once  // NOLINT

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include "basewidget.hpp"

class Header : public BaseWidget {
    Q_OBJECT
 public:
    explicit Header(QWidget *parent = nullptr);
    ~Header() override {}
 public slots:
    void logout() {}

 private:
    QPushButton *logoutBtn;
    QLabel *nickname;
    QLabel *icon;
    QLabel *logo;
    QHBoxLayout *mainLayout;
    QVBoxLayout *rightLayout;
    void setrightLayout();

 protected:
    void initLayout() override {}
    void initStyles() override {}
};

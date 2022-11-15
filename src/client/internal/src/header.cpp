#include "header.hpp"

#include <QHBoxLayout>
#include <QPainter>
#include <QPushButton>
#include <QStyle>
#include <QStyleOption>
#include <QWidget>

Header::Header(QWidget* parent)
    : QWidget(parent), logout_btn(new QPushButton("выйти", this)), profile_btn(new QPushButton("nickname", this)),
      avatar(new QLabel), logo(new QLabel("Logo", this)), layout(new QHBoxLayout), btnLayout(new QVBoxLayout) {
    initAvatar();
    setBtnLayout();
    setMinimumHeight(70);
    setMaximumHeight(90);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
    initLayout();
    initStyles();
}

void Header::initBtn(QPushButton* btn, QString iconPath) {
    btn->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed, QSizePolicy::ToolButton));
    btn->setIconSize(QSize(20, 20));
    // TODO(Kirill): Поправить подключение шрифта.

    btn->setFont(QFont("://fonts/JetBrainsMono-Light.ttf"));
    if (iconPath != "") {
        btn->setIcon(QIcon(iconPath));
    }
}

void Header::setBtnLayout() {
    btnLayout->setContentsMargins(QMargins(0, 0, 0, 0));
    initBtn(profile_btn, "");
    initBtn(logout_btn, "://images/logout.png");
    btnLayout->addWidget(profile_btn);
    btnLayout->addWidget(logout_btn);
}

void Header::initAvatar() {
    avatar->setObjectName("avatar");
    avatar->setFixedSize(QSize(60, 60));
    avatar->setAccessibleName("avatar");
}

void Header::initLayout() {
    layout->addWidget(logo);
    layout->addWidget(avatar);
    layout->addItem(btnLayout);
    layout->setContentsMargins(QMargins(10, 0, 10, 0));
    setLayout(layout);
}

void Header::paintEvent(QPaintEvent*) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Header::initStyles() {
    setStyleSheet(
        "Header {"
        "background-color: #5BAAEC;"
        "}"
        "QLabel {"
        "color: #f00;"
        "font-size: 36px;"
        "}"
        "#avatar {"
        "border-radius: 5px;"
        "background-size: cover;"
        "background-color: #FFFFFF;"
        "}"
        "QPushButton {"
        "padding: 0px;"
        "font-size: 2rem;"
        "color: #33425B;"
        "border: 0px;"
        "background-color: #5BAAEC;"
        "}"
        "QPushButton::hover {"
        "border-bottom: 1px solid;"
        "border-color: #33425B;"
        "}"
        "QPushButton::focus {"
        "outline: 0px;"
        "}");
}

#include "header.hpp"

#include <QHBoxLayout>
#include <QPainter>
#include <QPushButton>
#include <QStyle>
#include <QStyleOption>
#include <QWidget>

Header::Header(QWidget* parent)
    : BaseWidget(parent),
      logoutBtn(new QPushButton("выйти", this)),
      nickname(new QLabel("Nickname", this)), icon(new QLabel),
      logo(new QLabel(this)), mainLayout(new QHBoxLayout), rightLayout(new QVBoxLayout) {
    nickname->setObjectName("nickname");
    initAvatar();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    logo->setPixmap(QPixmap("://images/logo_resized.png"));
    setRightLayout();
    setMinimumHeight(70);
    setMaximumHeight(90);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
    initLayout();
    initStyles();
}

void Header::initBtn(QPushButton* btn, QString iconPath) {
    btn->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed, QSizePolicy::ToolButton));
    btn->setIconSize(QSize(18, 18));

    btn->setFont(QFont("://fonts/JetBrainsMono-Light.ttf"));
    if (iconPath != "") {
        btn->setIcon(QIcon(iconPath));
    }
}

void Header::setRightLayout() {
    rightLayout->setContentsMargins(QMargins(10, 10, 10, 10));
    initBtn(logoutBtn, "://images/logout.png");
    rightLayout->addWidget(nickname);
    rightLayout->addWidget(logoutBtn);
}

void Header::initAvatar() {
    icon->setObjectName("icon");
    icon->setFixedSize(QSize(60, 60));
}

void Header::initLayout() {
    mainLayout->addWidget(logo);
    mainLayout->addWidget(icon);
    mainLayout->addItem(rightLayout);
    mainLayout->setContentsMargins(QMargins(10, 0, 10, 0));
    setLayout(mainLayout);
}

void Header::initStyles() {
    setStyleSheet(
        "Header {"
        "background-color: #5BAAEC;"
        "}"
        "#nickname {"
        "color: #33425B;"
        "font-size: 20px;"
        "}"
        "#icon {"
        "border-radius: 5px;"
        "background-size: cover;"
        "background-color: #FFFFFF;"
        "}"
        "QPushButton {"
        "padding: 0px;"
        "font-size: 20px;"
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

#include "searchmenu.hpp"

SearchMenu::SearchMenu(QWidget* parent) : BaseWidget(parent),
                                          searchInput(new QLineEdit(this)),
                                          layout(new QVBoxLayout),
                                          searchLayout(new QHBoxLayout),
                                          btnLayout(new QHBoxLayout),
                                          searchBtn(new QPushButton(this)),
                                          showActiveContests(new QPushButton("Активные", this)),
                                          showFinishedContests(new QPushButton("Законченные", this)),
                                          myContestsCheckbox(new QCheckBox("Показать только мои", this)) {
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    setContentsMargins(10, 10, 10, 10);
    initBtnLayout();
    initSearchLayout();
    initMenuLayout();
    setLayout(layout);
    initStyles();
}

void SearchMenu::initBtnLayout() {
    btnLayout->addWidget(showFinishedContests);
    btnLayout->addWidget(showActiveContests);
}

void SearchMenu::initSearchLayout() {
    searchLayout->addWidget(searchInput);
    searchLayout->addWidget(searchBtn);
}

void SearchMenu::initMenuLayout() {
    searchBtn->setIconSize(QSize(25, 25));
    searchBtn->setIcon(QIcon("://images/search.png"));
    searchBtn->setObjectName("searchBtn");
    layout->setSpacing(15);
    layout->addLayout(searchLayout);
    layout->addLayout(btnLayout);
    layout->addWidget(myContestsCheckbox);
}

void SearchMenu::initStyles() {
    setStyleSheet(
        "SearchMenu {"
        "background-color: #33425B;"
        "border: 1.5px solid;"
        "border-color: #5BAAEC;"
        "border-radius: 30px;"
        "font-size: 20px;"
        "}"
        "#searchBtn {"
        "border: none;"
        "}"
        "QPushButton {"
        "color: #5BAAEC;"
        "border-radius: 15px;"
        "padding: 5px 10px;"
        "font-size: 20px;"
        "border: 1.5px solid #5BAAEC;"
        "}"
        "QPushButton:hover {"
        "background-color: #5BAAEC;"
        "color: #33425B;"
        "}"

        "QPushButton:focus {"
        "outline: 0px;"
        "}"

        "#searchBtn:hover {"
        "border-radius: 15px;"
        "border: 1.5px solid;"
        "border-color: #5BAAEC;"
        "background: #33425B;"
        "}"

        "QLineEdit {"
        "background-color: #FFFFFF;"
        "border-radius: 15px;"
        "font-size: 20px;"
        "color: #5BAAEC;"
        "}"
        "QCheckBox {"
        "color: #5BAAEC;"
        "font-size: 20px;"
        "}"
        "QCheckBox::indicator {"
        "width: 25px;"
        "height: 25px"
        "}"
        "QCheckBox:focus {"
        "outline: 0px;"
        "}");
}

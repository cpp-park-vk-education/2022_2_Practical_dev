#include "mainfragment.hpp"

MainFragment::MainFragment() : header(new Header(this)),
                               searchMenu(new SearchMenu(this)),
                               contestList(new ContestsList()),
                               layout(new QVBoxLayout) {
    layout->addWidget(header);
    layout->setContentsMargins(0, 0, 0, 0);
    QHBoxLayout* secondLayout = new QHBoxLayout();
    QPushButton* creationBtn = new QPushButton("Создать соревнование");
    QVBoxLayout* menuLayout = new QVBoxLayout();
    menuLayout->addWidget(searchMenu);
    menuLayout->addWidget(creationBtn);
    menuLayout->addStretch();
    secondLayout->addWidget(contestList);
    secondLayout->addLayout(menuLayout);
    secondLayout->setStretch(0, 3);
    secondLayout->setStretch(1, 1);
    secondLayout->setContentsMargins(10, 5, 10, 5);
    layout->addLayout(secondLayout);
    setLayout(layout);
    connect(creationBtn, SIGNAL(clicked()), SLOT(onCreateContest()));
    setStyleSheet(
        "MainFragment {"
        "background-color: #33425B;"
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
        "}");
}

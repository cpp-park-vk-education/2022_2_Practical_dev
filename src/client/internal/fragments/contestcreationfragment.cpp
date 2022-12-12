#include "contestcreationfragment.hpp"

ContestCreationFragment::ContestCreationFragment() : layout(new QVBoxLayout), contestConfig(new ContestConfig(this)) {
    Header* header = new Header(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(header);
    QWidget* tmp = new QWidget(this);
    tmp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QHBoxLayout* secondLayout = new QHBoxLayout();
    secondLayout->addWidget(tmp);
    secondLayout->addWidget(contestConfig);
    layout->addLayout(secondLayout);
    secondLayout->setStretch(0, 3);
    secondLayout->setStretch(1, 2);
    setLayout(layout);
    setStyleSheet(
        "ContestCreationFragment {"
        "background-color: #33425B;"
        "}");
}

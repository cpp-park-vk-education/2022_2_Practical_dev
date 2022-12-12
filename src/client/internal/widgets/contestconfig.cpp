#include "contestconfig.hpp"

ContestConfig::ContestConfig(QWidget* parent) : BaseWidget(parent),
                                                layout(new QVBoxLayout(this)),
                                                nameInput(new QLineEdit(this)),
                                                descriptionInput(new QTextEdit(this)),
                                                passwordInput(new QLineEdit(this)),
                                                startDateInput(new QDateTimeEdit(this)),
                                                endDate(new QDateTimeEdit(this)),
                                                configBtn(new QPushButton("Создать", this)) {
    nameInput->setObjectName("nameInput");
    descriptionInput->setObjectName("descriptionInput");
    passwordInput->setObjectName("passwordInput");
    startDateInput->setObjectName("startDateInput");
    endDate->setObjectName("endDate");
    configBtn->setObjectName("configBtn");
    initLayout();
    initStyles();
}
void ContestConfig::initLayout() {
    layout->addWidget(nameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(descriptionInput);
    QHBoxLayout* tmpLayout = new QHBoxLayout();
    tmpLayout->addWidget(startDateInput);
    tmpLayout->addWidget(endDate);
    layout->addLayout(tmpLayout);
    layout->addWidget(configBtn);
    layout->setStretch(0, 100);
    layout->setStretch(1, 2);
    layout->setStretch(2, 2);
    layout->setStretch(3, 2);
    layout->setStretch(4, 2);
    setLayout(layout);
}

void ContestConfig::initStyles() {
    setStyleSheet(
        "QLineEdit, QTextEdit {"
        "background-color: #FFFFFF;"
        "border-radius: 15px;"
        "font-size: 20px;"
        "color: #5BAAEC;"
        "}"
        "QDateTimeEdit {"
        "background-color: #FFFFFF;"
        "border-radius: 10px;"
        "color: #5BAAEC;"
        "}");
}

#include "mainwindow.hpp"

#include "contestspage.hpp"
#include "header.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), layout(new QVBoxLayout), mainTab(new QStackedWidget) {
    ui->setupUi(this);
    Header* header = new Header(this);
    ContestsPage* page = new ContestsPage();
    mainTab->addWidget(page);
    layout->addWidget(header);
    layout->addWidget(mainTab);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    ui->centralwidget->setLayout(layout);
    initStyles();
}

void MainWindow::initStyles() {
    mainTab->setStyleSheet(
        "QStackedWidget {"
        "background-color: #33425B;"
        "}");
}

MainWindow::~MainWindow() {
    delete ui;
}

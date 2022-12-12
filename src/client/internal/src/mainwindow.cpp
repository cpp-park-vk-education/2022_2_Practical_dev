#include "mainwindow.hpp"

#include <QStackedWidget>

#include "navigator.hpp"
#include "screensfactory.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), container(new QStackedWidget), factory(new ScreensFactory) {
    ui->setupUi(this);
    navigator = new Navigator(container, factory);
    container->setContentsMargins(0, 0, 0, 0);
    setCentralWidget(container);
}

MainWindow::~MainWindow() {
    delete ui;
}

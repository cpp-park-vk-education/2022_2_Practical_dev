#include "mainwindow.hpp"

#include <QStackedWidget>

#include "navigator.hpp"
#include "screensfactory.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

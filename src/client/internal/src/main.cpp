#include <QApplication>

#include "mainwindow.hpp"
#include "navigator.hpp"
#include "screensfactory.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

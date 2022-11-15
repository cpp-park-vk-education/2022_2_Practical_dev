#pragma once  // NOLINT

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 private:
    Ui::MainWindow *ui;
    QVBoxLayout *layout;
    QStackedWidget *mainTab;
    void initStyles();
};

#pragma once  // NOLINT

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class Header : public QWidget {
    Q_OBJECT
 public:
    explicit Header(QWidget *parent = nullptr);
 private slots:

 private:
    void initStyles();
    void setBtnLayout();
    void initAvatar();
    void initBtn(QPushButton* btn, QString iconPath);
    void initLayout();
    void paintEvent(QPaintEvent *e);
    QPushButton *logout_btn;
    QPushButton *profile_btn;
    QLabel *avatar;
    QLabel *logo;
    QHBoxLayout *layout;
    QVBoxLayout * btnLayout;
};

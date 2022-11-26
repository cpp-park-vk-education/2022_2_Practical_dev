#pragma once  // NOLINT
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "basewidget.hpp"

class ContestItem : public BaseWidget {
    Q_OBJECT

 public:
    explicit ContestItem(QWidget* parent = nullptr);
    ~ContestItem() override {}

 private:
    QLabel* name;
    QLabel* status;
    QLabel* author;
    QVBoxLayout* layout;
    QPushButton* controlBtn;

 protected:
    void initLayout() override {}
    void initStyles() override {}
 signals:
    void showContest(size_t id);
 public slots:
    void onShowContest(size_t id) {}
};

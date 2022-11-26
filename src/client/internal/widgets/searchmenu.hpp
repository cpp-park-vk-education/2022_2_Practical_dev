#pragma once  // NOLINT
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "basewidget.hpp"
#include "contestslist.hpp"

class SearchMenu : public BaseWidget {
    Q_OBJECT

 public:
    explicit SearchMenu(QWidget* parent = nullptr);
    ~SearchMenu() override{};

 private:
    ContestsList* list;
    QVBoxLayout* layout;
    QLineEdit* searchInput;
    QPushButton* searchBtn;
    QPushButton* showActiveContests;
    QPushButton* showFinishedContests;
    QCheckBox* myContestsCheckbox;

 protected:
    void initLayout() override {}
    void initStyles() override {}
 private slots:
    void onSearch(QString name) {}
    void onShowActive() {}
    void onShowFinished() {}
    void onShowMyContests() {}

 signals:
    void search(QString name);
};

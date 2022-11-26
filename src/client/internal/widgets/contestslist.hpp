#pragma once  // NOLINT
#include <QScrollArea>
#include <QScrollBar>

#include "basewidget.hpp"
#include "contestitem.hpp"

class ContestsList : BaseWidget {
    Q_OBJECT

 public:
    explicit ContestsList(QWidget* parent = nullptr);
    ~ContestsList() override {}
    ContestItem* makeContestItem() {}
    void addItem(ContestItem* Item) {}
    void fill() {}

 private:
    QScrollArea* container;
    QGridLayout* layout;
    QScrollBar* scrollBar;

 protected:
    void initLayout() override {}
    void initStyles() override {}
};

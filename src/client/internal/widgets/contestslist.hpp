#pragma once  // NOLINT
#include <QGridLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QSizePolicy>

#include "basewidget.hpp"
#include "contestitem.hpp"

class ContestsList : public BaseWidget {
    Q_OBJECT

 public:
    explicit ContestsList(QWidget* parent = nullptr) : BaseWidget(parent), layout(new QVBoxLayout(this)) {
        initLayout();
        initStyles();
    }
    ~ContestsList() override {}
    ContestItem* makeContestItem() {}
    void addItem(ContestItem* Item) {}
    void fill() {}

 private:
    QScrollArea* container;
    QVBoxLayout* layout;
    QScrollBar* scrollBar;

 protected:
    void initLayout() override { setLayout(layout); }
    void initStyles() override {
        setStyleSheet(
            "ContestsList {"
            "background-color: #33425B;"
            "border: 1.5px solid;"
            "border-color: #5BAAEC;"
            "border-radius: 30px;"
            "}");
    }
};

#pragma once  // NOLINT
#include <QScrollBar>
#include <QStackedWidget>
#include <QTextEdit>

#include "basefragment.hpp"
#include "header.hpp"

class ContestFragment : public BaseFragment {
    Q_OBJECT
 public:
    ContestFragment();
    ~ContestFragment() override{};

 private:
    QStackedWidget* container;
    Header* header;
    QLabel* contestName;
    QLabel* description;
    QWidget* taskLitst;
    QVBoxLayout* layout;
    void setData();
 public slots:
    void switchTask(size_t id);
};

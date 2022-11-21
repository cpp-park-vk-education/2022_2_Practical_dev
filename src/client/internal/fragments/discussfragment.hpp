#pragma once  // NOLINT
#include <QScrollBar>
#include <QTextEdit>

#include "basefragment.hpp"
#include "header.hpp"
class DiscussFragment : public BaseFragment {
    Q_OBJECT
 public:
    DiscussFragment();
    ~DiscussFragment() override{};

 private:
    Header* header;
    QHBoxLayout* layout;
    QScrollBar* scrollBar;
    QTextEdit* commentInput;
    QPushButton* commentBtn;
    void setData();

 public slots:
    void switchTask();
    void showSolution(size_t id);
};

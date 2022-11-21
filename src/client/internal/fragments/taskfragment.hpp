#pragma once  // NOLINT
#include <QHBoxLayout>
#include <QTextEdit>

#include "basefragment.hpp"
#include "parcelslist.hpp"
#include "taskwidget.hpp"

class TaskFragment : public BaseFragment {
    Q_OBJECT
 public:
    TaskFragment();
    ~TaskFragment() override{};

 private:
    QHBoxLayout* layout;
    ParcelsList* parcelsList;
    QTextEdit* codeInput;
    TaskWidget* task;
    QPushButton* sendBtn;
    void setData();
 public slots:
    void switchTask(size_t id);
 signals:
    void send();
};

#pragma once  // NOLINT

#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>

#include "basewidget.hpp"

class TaskWidget : BaseWidget {
    Q_OBJECT
 public:
    explicit TaskWidget(QWidget* parent = nullptr);
    ~TaskWidget();

 private:
    QLabel* taskName;
    QScrollArea* container;
    QVBoxLayout* layout;
    QLabel* task;
    QScrollBar* scrollBar;
    QPushButton* nextBtn;
    QPushButton* prevBtn;

 protected:
    void initLayout() override;
    void initStyles() override;
    void setData() override;
 signals:
    void nextTask(size_t id);
    void prevTask(size_t id);
};

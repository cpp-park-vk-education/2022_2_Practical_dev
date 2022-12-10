#pragma once  // NOLINT
#include <QWidget>

class BaseWidget : public QWidget {
    Q_OBJECT
 public:
    explicit BaseWidget(QWidget* parent = nullptr);
    virtual ~BaseWidget() {}

 protected:
    void paintEvent(QPaintEvent* event) {}
    virtual void initLayout() = 0;
    virtual void initStyles() = 0;
};

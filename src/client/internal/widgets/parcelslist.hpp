#pragma once  // NOLINT

#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>

#include "basewidget.hpp"

class ParcelsList : BaseWidget {
    Q_OBJECT

 public:
    explicit ParcelsList(QWidget* parent = nullptr);
    ~ParcelsList();

 private:
    QVBoxLayout* layout;
    QScrollArea* container;
    QScrollBar* scrollBar;
    QLayout* id;
    QLayout* ML;
    QLayout* TL;
    QLayout* status;
    void fill();

 protected:
    void initLayout() override;
    void initStyles() override;
    void setData() override;
 public slots:
    void send(size_t id);
};

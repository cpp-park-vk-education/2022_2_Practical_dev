#pragma once  // NOLINT
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "basewidget.hpp"

class CommentItem : public BaseWidget {
    Q_OBJECT
 public:
    explicit CommentItem(BaseWidget* parent = nullptr);
    ~CommentItem() override {}

 private:
    QLabel* text;
    QLabel* rating;
    QPushButton* likeBtn;
    QLabel* parcel;
    QHBoxLayout* layout;

 protected:
    void initLayout() override {}
    void initStyles() override {}
 private slots:
    void onLike(size_t id) {}
 signals:
    void showSolution();
    void like();
};

#include "basewidget.hpp"

#include <QPainter>
#include <QStyle>
#include <QStyleOption>

void BaseWidget::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

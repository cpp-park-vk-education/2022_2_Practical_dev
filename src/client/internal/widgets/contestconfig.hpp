#pragma once  // NOLINT

#include <QDateTimeEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

#include "basewidget.hpp"

class ContestConfig : public BaseWidget {
    Q_OBJECT
 public:
    explicit ContestConfig(QWidget* parent);

 public slots:
    void onCreateContest();

 private:
    QVBoxLayout* layout;
    QLineEdit* nameInput;
    QTextEdit* descriptionInput;
    QLineEdit* passwordInput;
    QDateTimeEdit* startDateInput;
    QDateTimeEdit* endDate;
    QPushButton* configBtn;
    bool validate();
};

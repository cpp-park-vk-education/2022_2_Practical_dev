#pragma once  // NOLINT

#include <QBoxLayout>
#include <QLineEdit>
#include <QTextEdit>

#include "basewidget.hpp"

class TaskConfig : public BaseWidget {
    Q_OBJECT

 public:
    explicit TaskConfig(QWidget* parent = nullptr);
    ~TaskConfig();

 private:
    QLineEdit* nameInput;
    QTextEdit* descriptionInput;
    QLineEdit* costInput;
    QLineEdit* MLInput;
    QLineEdit* TLInput;
    QTextEdit* indataInput;
    QTextEdit* outdataInput;
    QBoxLayout* layout;

 protected:
    void initLayout() override;
    void initStyles() override;
    void setData() override;
 public slots:
    void onAddTest(QString in, QString out);
 signals:
    void addTest(QString in, QString out);
    void addTask();
};

#pragma once  // NOLINT
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "basefragment.hpp"

class SignInFragment : public BaseFragment {
    Q_OBJECT
 public:
    SignInFragment();
    ~SignInFragment() {}

 private:
    QVBoxLayout* layout;
    QLineEdit* loginInput;
    QLineEdit* passwordInput;
    QPushButton* submitBtn;
    QPushButton* registerBtn;
 public slots:
    void onRegister() {}
    void onLogin() {}
};

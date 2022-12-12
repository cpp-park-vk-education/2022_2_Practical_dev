#pragma once  // NOLINT

#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>

#include "basefragment.hpp"

class RegisterFragment : public BaseFragment {
    Q_OBJECT
 public:
    RegisterFragment() {}
    ~RegisterFragment() {}

 private:
    QBoxLayout* layout;
    QPushButton* registerBtn;
    QPushButton* signinBtn;
    QLineEdit* emailInput;
    QLineEdit* nicknameInput;
    QLineEdit* passwordInput;
    QLineEdit* checkPasswordInput;
 public slots:
    void onLogin() {}
    void onRgister() {}
};

#pragma once  // NOLINT

#include <QString>

#include "basefragment.hpp"

namespace Screens {
static const QString SIGNIN_TAG = "sigin";
static const QString REGISTER_TAG = "register";
static const QString MAIN_TAG = "main";
static const QString TASK_TAG = "task";
static const QString CONTEST_CONFIGURATION_TAG = "contest_configuration";
static const QString CONTEST_TAG = "contest";
static const QString DISCUSS_TAG = "discuss";

}  // namespace Screens

class ScreensFactory {
 public:
    ScreensFactory();
    ~ScreensFactory();
    BaseFragment* create(QString tag);
    QString getStart();
};

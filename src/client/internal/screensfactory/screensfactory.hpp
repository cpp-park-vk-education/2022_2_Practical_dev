#pragma once  // NOLINT

#include <QString>

#include "basefragment.hpp"
#include "contestcreationfragment.hpp"
#include "discussfragment.hpp"
#include "mainfragment.hpp"
#include "registerfragment.hpp"
#include "signinfragment.hpp"
#include "taskfragment.hpp"

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
    ScreensFactory() = default;
    ~ScreensFactory() = default;
    BaseFragment* create(QString tag) {
        if (tag == Screens::SIGNIN_TAG) {
            return new SignInFragment;
        }
        if (tag == Screens::REGISTER_TAG) {
            return new RegisterFragment;
        }
        if (tag == Screens::MAIN_TAG) {
            return new MainFragment;
        }
        if (tag == Screens::TASK_TAG) {
            return new TaskFragment;
        }
        if (tag == Screens::CONTEST_CONFIGURATION_TAG) {
            return new ContestCreationFragment;
        }
        if (tag == Screens::CONTEST_TAG) {
            return new TaskFragment;
        }
        if (tag == Screens::DISCUSS_TAG) {
            return new DiscussFragment;
        }
        return nullptr;
    }

    QString getStart() { return Screens::MAIN_TAG; }
};

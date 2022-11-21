#pragma once  // NOLINT

#include <QHBoxLayout>

#include "basefragment.hpp"
#include "contestconfig.hpp"
#include "taskconfig.hpp"

class ContestCreationFragment : public BaseFragment {
    Q_OBJECT
 public:
    ContestCreationFragment();
    ~ContestCreationFragment() override{};

 private:
    QHBoxLayout* layout;
    ContestConfig* contestCofig;
    TaskConfig* taskConfig;
 public slots:
    void onCreate();
};

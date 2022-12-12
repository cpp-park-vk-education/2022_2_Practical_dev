#pragma once  // NOLINT

#include <QHBoxLayout>
#include <QSizePolicy>

#include "basefragment.hpp"
#include "contestconfig.hpp"
#include "header.hpp"
#include "taskconfig.hpp"

class ContestCreationFragment : public BaseFragment {
    Q_OBJECT
 public:
    ContestCreationFragment();
    ~ContestCreationFragment() {}

 private:
    QVBoxLayout* layout;
    ContestConfig* contestConfig;
    TaskConfig* taskConfig;
 public slots:
    void onCreate() {}
};

#pragma once  // NOLINT
#include <QHBoxLayout>
#include <QSpacerItem>
#include <iostream>

#include "basefragment.hpp"
#include "contestslist.hpp"
#include "header.hpp"
#include "searchmenu.hpp"

class MainFragment : public BaseFragment {
    Q_OBJECT
 public:
    MainFragment();
    ~MainFragment() {}

 private:
    Header* header;
    ContestsList* contestList;
    SearchMenu* searchMenu;
    QVBoxLayout* layout;
 public slots:
    void onSearch() {}
    void onCreateContest() {
        emit navigateTo("contest_configuration");
    }
    void onShowActive() {}
    void onShowFinished() {}
    void onShowMyContests() {}
};

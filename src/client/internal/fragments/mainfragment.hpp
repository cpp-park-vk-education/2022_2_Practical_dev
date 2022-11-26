#pragma once  // NOLINT
#include <QHBoxLayout>

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
    QHBoxLayout* layout;
 private slots:
    void onSearch(QString name) {}
    void onShowActive() {}
    void onShowFinished() {}
    void onShowMyContests() {}
};

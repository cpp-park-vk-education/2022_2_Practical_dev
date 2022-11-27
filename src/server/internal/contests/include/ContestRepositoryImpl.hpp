#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "ContestRepository.hpp"
#include "DBManager.hpp"

class DBContestImpl : DBContest {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    DBContestImpl();

    Contest Select(const Contest& contest);
    Contest Add(const Contest& obj);

    int DeleteUserFromContest(const Contest& obj, const User& user);
    int AddUserIntoContest(const Contest& obj, const User& user);
    int GetUsersByContest(const Contest& obj, const User& user);

    int DeleteTaskFromContest(const Contest& obj, const Task& user);
    int AddTaskIntoContest(const Contest& obj, const Task& user);
    std::vector<Task> GetTasksByContest(const Contest& obj);

    int Delete(const Contest& obj);
};

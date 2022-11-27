#pragma once

#include <pqxx/pqxx>

#include "Contest.hpp"
#include "Task.hpp"
#include "User.hpp"

class DBContest {
 private:
 public:
    DBContest();

    virtual Contest Select(const Contest& contest);
    virtual Contest Add(const Contest& obj);

    virtual int DeleteUserFromContest(const Contest& obj, const User& user);
    virtual int AddUserIntoContest(const Contest& obj, const User& user);
    virtual int GetUsersByContest(const Contest& obj, const User& user);

    virtual int DeleteTaskFromContest(const Contest& obj, const Task& user);
    virtual int AddTaskIntoContest(const Contest& obj, const Task& user);
    virtual std::vector<Task> GetTasksByContest(const Contest& obj);

    virtual int Delete(const Contest& obj);
};

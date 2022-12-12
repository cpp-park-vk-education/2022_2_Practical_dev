#pragma once

#include <pqxx/pqxx>

#include "Contest.hpp"
#include "Task.hpp"
#include "User.hpp"

class ContestRepository {
 private:
 public:
    ContestRepository() = default;

    virtual Contest Select(const Contest& contest) = 0;
    virtual std::vector<Contest> SelectAll() = 0;
    virtual Contest Add(const Contest& obj) = 0;

    virtual int DeleteUserFromContest(const Contest& obj, const User& user) = 0;
    virtual int AddUserIntoContest(const Contest& obj, const User& user) = 0;
    virtual std::vector<User> GetUsersByContest(const Contest& obj) = 0;

    virtual int DeleteTaskFromContest(const Contest& obj, const Task& task) = 0;
    virtual int AddTaskIntoContest(const Contest& obj, const Task& task) = 0;
    virtual std::vector<Task> GetTasksByContest(const Contest& obj) = 0;

    virtual int Delete(const Contest& obj) = 0;

    ~ContestRepository() = default;
};

#pragma once

#include <iostream>
#include "User.hpp"
#include "Task.hpp"
#include "Contest.hpp"

class IContestAPI {
 public:
    IContestAPI();

    virtual Contest getContest(const size_t idContest) = 0;
    virtual std::vector<Task> getTask(const size_t idContest) = 0;
    virtual std::vector<User> getUser(const size_t idContest) = 0;

    virtual Contest createContest(const Constent& contest) = 0;

    virtual User addUser(const size_t idContest, const size_t idUser) = 0;
    virtual Task addTask(const size_t idContest, const size_t idTask) = 0;

    virtual void deleteContest(const size_t idContest) = 0;
    virtual void deleteUser(const size_t idUser, const size_t idContest) = 0;
    virtual void deleteTask(const size_t idTask, const size_t idContest) = 0;

};

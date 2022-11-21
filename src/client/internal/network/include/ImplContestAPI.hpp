#pragma once

#include "IContestAPI.hpp"

class ImplContestAPI: public IContestAPI {
 public:
    ImplContestAPI();

    virtual Contest getContest(const size_t idContest);
    virtual std::vector<Task> getTask(const size_t idContest);
    virtual std::vector<User> getUser(const size_t idContest);

    virtual Contest createContest(const Constent& contest);

    virtual User addUser(const size_t idContest, const size_t idUser);
    virtual Task addTask(const size_t idContest, const size_t idTask);

    virtual void deleteContest(const size_t idContest);
    virtual void deleteUser(const size_t idUser, const size_t idContest);
    virtual void deleteTask(const size_t idTask, const size_t idContest);

};

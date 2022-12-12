#pragma once

#include <vector>
#include "IContestAPI.hpp"

class ImplContestAPI: public IContestAPI {
 public:
    ImplContestAPI();
    ~ImplContestAPI();

    Contest getContest(const size_t idContest) override;
    std::vector<Task> getTask(const size_t idContest) override;
    std::vector<User> getUser(const size_t idContest) override;

    Contest createContest(const Contest& contest) override;

    User addUser(const size_t idContest, const size_t idUser) override;
    Task addTask(const size_t idContest, const size_t idTask) override;

    void deleteContest(const size_t idContest) override;
    void deleteUser(const size_t idUser, const size_t idContest) override;
    void deleteTask(const size_t idTask, const size_t idContest) override;
};

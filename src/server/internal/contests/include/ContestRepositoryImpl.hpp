#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "ContestRepository.hpp"
#include "DBManager.hpp"

class ContestRepositoryImpl : ContestRepository {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    ContestRepositoryImpl();

    Contest Select(const Contest& contest) override;
    Contest Add(const Contest& obj) override;

    int DeleteUserFromContest(const Contest& obj, const User& user) override;
    int AddUserIntoContest(const Contest& obj, const User& user) override;
    int GetUsersByContest(const Contest& obj, const User& user) override;

    int DeleteTaskFromContest(const Contest& obj, const Task& user) override;
    int AddTaskIntoContest(const Contest& obj, const Task& user) override;
    std::vector<Task> GetTasksByContest(const Contest& obj) override;

    int Delete(const Contest& obj);
};

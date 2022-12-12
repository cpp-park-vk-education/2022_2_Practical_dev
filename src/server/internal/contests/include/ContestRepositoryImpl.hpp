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
    std::vector<Contest> SelectAll() override;
    Contest Add(const Contest& obj) override;

    int DeleteUserFromContest(const Contest& obj, const User& user) override;
    int AddUserIntoContest(const Contest& obj, const User& user) override;
    std::vector<User> GetUsersByContest(const Contest& obj) override;

    int DeleteTaskFromContest(const Contest& obj, const Task& task) override;
    int AddTaskIntoContest(const Contest& obj, const Task& task) override;
    std::vector<Task> GetTasksByContest(const Contest& obj) override;

    int Delete(const Contest& obj);
};

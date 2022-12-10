#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "DBManager.hpp"
#include "UserRepository.hpp"

class UserRepositoryImpl : UserRepository {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    UserRepositoryImpl();

    User Get(const User& user) override;
    User GetById(const std::size_t& id) override;
    std::vector<User> GetByContest(const size_t& id) override;
    std::vector<User> GetByTask(const size_t& id) override;

    User Update(const User& obj) override;

    int Signin(const User& user) override;
    int Signup(const User& user) override;

    int DeleteContest(const User& user, const Contest& contest) override;
    int AddContest(const User& user, const Contest& contest) override;
    std::vector<Contest> GetContestsByUser(const User& user) override;
};

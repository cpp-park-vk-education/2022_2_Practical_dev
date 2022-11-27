#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "DBManager.hpp"
#include "UserRepository.hpp"

class DBUserImpl : DBUser {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    DBUserImpl();

    User Get(const User& user);
    User GetById(const std::size_t& id);
    std::vector<User> GetByContest(const size_t& id);
    std::vector<User> GetByTask(const size_t& id);
    User Update(const User& obj);
    int Signin(const User& user);
    int Signup(const User& user);
    int DeleteContest(const User& user, const Contest& contest);
    int AddContest(const User& user, const Contest& contest);
    std::vector<Contest> GetContestsByUser(const User& user);
};

#pragma once

#include <pqxx/pqxx>

#include "Contest.hpp"
#include "User.hpp"

class UserRepository {
 private:
 public:
    UserRepository() = default;

    virtual User Get(const User& user) = 0;
    virtual User GetById(const std::size_t& id) = 0;
    virtual std::vector<User> GetByContest(const size_t& id) = 0;
    virtual std::vector<User> GetByTask(const size_t& id) = 0;

    virtual User Update(const User& obj) = 0;

    virtual int Signin(const User& user) = 0;
    virtual int Signup(const User& user) = 0;

    virtual int DeleteContest(const User& user, const Contest& contest) = 0;
    virtual int AddContest(const User& user, const Contest& contest) = 0;
    virtual std::vector<Contest> GetContestsByUser(const User& user) = 0;

    ~UserRepository() = default;
};

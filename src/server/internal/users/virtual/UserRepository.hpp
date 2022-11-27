#pragma once

#include <pqxx/pqxx>

#include "Contest.hpp"
#include "User.hpp"

class DBUser {
 private:
 public:
    DBUser();

    virtual User Get(const User& user);
    virtual User GetById(const std::size_t& id);
    virtual std::vector<User> GetByContest(const size_t& id);
    virtual std::vector<User> GetByTask(const size_t& id);
    virtual User Update(const User& obj);
    virtual int Signin(const User& user);
    virtual int Signup(const User& user);
    virtual int DeleteContest(const User& user, const Contest& contest);
    virtual int AddContest(const User& user, const Contest& contest);
    virtual std::vector<Contest> GetContestsByUser(const User& user);
};

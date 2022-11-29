#pragma once

#include <set>

#include "contests/contests.hpp"

class User;

class UserInterface {
 public:
    virtual User signin(User &user) = 0;
    virtual User signup(User &user) = 0;

    virtual User get(User &user) = 0;
    virtual std::set<Contest> get_contests(User &user) = 0;

    virtual User modify(User &user) = 0;

    virtual int add_contest(User &user) = 0;
    virtual int delete_contest(User &user) = 0;
};

class DBUser;

class UserInterface {
    DBUser &repository;
 public:
    User signin(User &user);
    User signup(User &user);

    User get(User &user);
    std::set<Contest> get_contests(User &user);

    User modify(User &user);

    int add_contest(User &user);
    int delete_contest(User &user);
};
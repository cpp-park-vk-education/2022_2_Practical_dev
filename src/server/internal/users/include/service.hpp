#pragma once

#include <set>

#include "contests/contests.hpp"

class User;

class UserInterface {
    static User signin(User &user);
    static User signup(User &user);

    static User get(User &user);
    static std::set<Contest> get_contests(User &user);

    static User modify(User &user);

    static int add_contest(User &user);
    static int delete_contest(User &user);
};
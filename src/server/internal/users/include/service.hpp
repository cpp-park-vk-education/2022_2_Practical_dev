#pragma once

#include <vector>

#include "contests/contests.hpp"

class User;

class UserInterface {
    static void signin(User &user);
    static void signup(User &user);
    static void auth(User &user);  // authorization

    static User get(User &user);
    static std::vector<Contest> get_contests(User &user);

    static void modify(User &user);

    static void add_contest(User &user);
    static void delete_contest(User &user);
};
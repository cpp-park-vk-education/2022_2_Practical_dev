#pragma once

#include <vector>

#include "users/users.hpp"
#include "tasks/tasks.hpp"

class Contest;

class ContestInterface {
    static void get(Contest &contest);
    static void modify(Contest &contest);
    static void remove(Contest &contest);

    static std::vector<Task> get_tasks(Contest &contest);
    static void set_task(Contest &contest);
    static void delete_task(Contest &contest);

    static std::vector<User> get_users(Contest &contest);
    static void add_user(Contest &contest);
    static void delete_user(Contest &contest);
};
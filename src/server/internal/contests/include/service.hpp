#pragma once

#include <set>

#include "users/users.hpp"
#include "tasks/tasks.hpp"

class Contest;

class ContestInterface {
    static Contest get(Contest &contest);
    static Contest modify(Contest &contest);
    static Contest remove(Contest &contest);

    static std::set<Task> get_tasks(Contest &contest);
    static Task set_task(Contest &contest, Task &task);
    static Task delete_task(Contest &contest, Task &task);

    static std::set<User> get_users(Contest &contest);
    static User add_user(Contest &contest, User &user);
    static User delete_user(Contest &contest, User &user);
};
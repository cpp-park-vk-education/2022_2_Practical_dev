#pragma once

#include <set>

#include "users/users.hpp"
#include "tasks/tasks.hpp"

class Contest;

class ContestServiceInterface {
 public:
    virtual Contest get(Contest &contest) = 0;
    virtual Contest modify(Contest &contest) = 0;
    virtual Contest remove(Contest &contest) = 0;

    virtual std::set<Task> get_tasks(Contest &contest) = 0;
    virtual Task set_task(Contest &contest, Task &task) = 0;
    virtual Task delete_task(Contest &contest, Task &task) = 0;

    virtual std::set<User> get_users(Contest &contest) = 0;
    virtual User add_user(Contest &contest, User &user) = 0;
    virtual User delete_user(Contest &contest, User &user) = 0;
};

class DBContest;

class ContestService : ContestServiceInterface {
    DBContest &repository;
 public:
    Contest get(Contest &contest);
    Contest modify(Contest &contest);
    Contest remove(Contest &contest);

    std::set<Task> get_tasks(Contest &contest);
    Task set_task(Contest &contest, Task &task);
    Task delete_task(Contest &contest, Task &task);

    std::set<User> get_users(Contest &contest);
    User add_user(Contest &contest, User &user);
    User delete_user(Contest &contest, User &user);
};
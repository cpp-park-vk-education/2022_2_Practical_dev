#pragma once

#include <set>

#include "parcels/parcels.hpp"
#include "comments/comments.hpp"

class Task;

class TaskServiceInterface {
 public:
    virtual Task get(Task &task) = 0;
    virtual std::set<Parcel> get_parcels(Task &task) = 0;
    virtual std::set<Comment> get_comments(Task &task) = 0;
};

class DBTask;

class TaskService : TaskServiceInterface {
    DBTask &repository;
 public:
    Task get(Task &task);
    std::set<Parcel> get_parcels(Task &task);
    std::set<Comment> get_comments(Task &task);
};
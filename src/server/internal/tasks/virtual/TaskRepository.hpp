#pragma once

#include <pqxx/pqxx>

#include "Comment.hpp"
#include "Parcel.hpp"
#include "Task.hpp"

class TaskRepository {
 private:
 public:
    TaskRepository() = default;

    virtual Task Select(const Task& task) = 0;

    virtual std::vector<Parcel> GetParcelsByTask(const Task& task) = 0;
    virtual std::vector<Comment> GetCommentsByTask(const Task& task) = 0;

    virtual Task Update(const Task& obj) = 0;
    virtual void Delete(const Task& obj) = 0;

    ~TaskRepository() = default;
};

#pragma once

#include <pqxx/pqxx>

#include "Comment.hpp"
#include "Parcel.hpp"
#include "Task.hpp"

class DBTask {
 private:
 public:
    DBTask();
    virtual Task Select(const Task& task);
    virtual std::vector<Parcel> GetParcelsByTask(const Task& task);
    virtual std::vector<Comment> GetCommentsByTask(const Task& task);
    virtual Task Update(const Task& obj);
    virtual void Delete(const Task& obj);
};

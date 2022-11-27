#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "DBManager.hpp"
#include "TaskRepository.hpp"

class DBTaskImpl : DBTask {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    DBTaskImpl();
    Task Select(const Task& task);
    std::vector<Parcel> GetParcelsByTask(const Task& task);
    std::vector<Comment> GetCommentsByTask(const Task& task);
    Task Update(const Task& obj);
    void Delete(const Task& obj);
};

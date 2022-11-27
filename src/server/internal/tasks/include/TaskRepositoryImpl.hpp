#pragma once

#include <pqxx/pqxx>

#include "TaskRepository.hpp"

class DBTaskImpl : DBTask {
 private:
    pqxx::work worker;

 public:
    DBTaskImpl();
    Task Select(const Task& task);
    std::vector<Parcel> GetParcelsByTask(const Task& task);
    std::vector<Comment> GetCommentsByTask(const Task& task);
    Task Update(const Task& obj);
    void Delete(const Task& obj);
};

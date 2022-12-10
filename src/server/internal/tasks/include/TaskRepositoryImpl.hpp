#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "DBManager.hpp"
#include "TaskRepository.hpp"

class TaskRepositoryImpl : TaskRepository {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    TaskRepositoryImpl();

    Task Select(const Task& task) override;

    std::vector<Parcel> GetParcelsByTask(const Task& task) override;
    std::vector<Comment> GetCommentsByTask(const Task& task) override;

    Task Update(const Task& obj) override;
    void Delete(const Task& obj) override;
};

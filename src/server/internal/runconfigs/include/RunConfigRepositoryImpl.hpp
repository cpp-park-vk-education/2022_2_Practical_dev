#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "DBManager.hpp"
#include "RunConfigsRepository.hpp"

class RunConfigRepositoryImpl : RunConfigRepository {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    RunConfigRepositoryImpl();

    RunConfig Select(const std::string& query) override;
    std::vector<RunConfig> SelectMany(const std::string& query, size_t n, size_t page = 1) override;

    RunConfig Insert(const RunConfig& obj) override;

    RunConfig Update(const RunConfig& obj) override;

    void Delete(const RunConfig& obj) override;
};

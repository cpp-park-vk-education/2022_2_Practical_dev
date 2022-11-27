#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "DBManager.hpp"
#include "RunConfigsRepository.hpp"

class DBRunConfigImpl : DBRunConfig {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    DBRunConfigImpl();

    RunConfig Select(const std::string& query);
    std::vector<RunConfig> SelectMany(const std::string& query, size_t n, size_t page = 1);

    RunConfig Insert(const RunConfig& obj);

    RunConfig Update(const RunConfig& obj);

    void Delete(const RunConfig& obj);
};

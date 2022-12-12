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

    RunConfig SelectById(const size_t& id) override;
    RunConfig SelectByName(const std::string& name) override;

    RunConfig Insert(const RunConfig& obj) override;

    int Update(const RunConfig& obj) override;

    int Delete(const RunConfig& obj) override;
};

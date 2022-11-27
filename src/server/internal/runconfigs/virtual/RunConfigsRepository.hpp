#pragma once

#include <pqxx/pqxx>

#include "RunConfig.hpp"

class RunConfigRepository {
 private:
 public:
    RunConfigRepository() = default;

    virtual RunConfig Select(const std::string& query);
    virtual RunConfig Select(const size_t& id);
    virtual std::vector<RunConfig> SelectMany(const std::string& query, size_t n, size_t page = 1);

    virtual RunConfig Insert(const RunConfig& obj);

    virtual RunConfig Update(const RunConfig& obj);

    virtual void Delete(const RunConfig& obj);

    ~RunConfigRepository() = default;
};

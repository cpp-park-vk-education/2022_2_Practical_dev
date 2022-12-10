#pragma once

#include <pqxx/pqxx>

#include "RunConfig.hpp"

class RunConfigRepository {
 private:
 public:
    RunConfigRepository() = default;

    virtual RunConfig Select(const std::string& query) = 0;
    virtual RunConfig Select(const size_t& id) = 0;
    virtual std::vector<RunConfig> SelectMany(const std::string& query, size_t n, size_t page = 1) = 0;

    virtual RunConfig Insert(const RunConfig& obj) = 0;

    virtual RunConfig Update(const RunConfig& obj) = 0;

    virtual void Delete(const RunConfig& obj) = 0;

    ~RunConfigRepository() = default;
};

#pragma once

#include <pqxx/pqxx>

#include "RunConfig.hpp"

class RunConfigRepository {
 private:
 public:
    RunConfigRepository() = default;

    virtual RunConfig SelectById(const size_t& id) = 0;
    virtual RunConfig SelectByName(const std::string& name) = 0;

    virtual RunConfig Insert(const RunConfig& obj) = 0;

    virtual int Update(const RunConfig& obj) = 0;

    virtual int Delete(const RunConfig& obj) = 0;

    ~RunConfigRepository() = default;
};

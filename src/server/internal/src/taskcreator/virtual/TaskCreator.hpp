#pragma once

#include "RunConfig.hpp"
#include "Task.hpp"

class TaskCreator {
 private:
 public:
    TaskCreator() = default;

    virtual int Setup(const Task& cfg, const RunConfig& sol_conf, const RunConfig& gen_conf) = 0;

    ~TaskCreator() = default;
};

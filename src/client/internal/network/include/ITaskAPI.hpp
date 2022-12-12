#pragma once

#include "Task.hpp"

class ITaskAPI {
 public:
    ITaskAPI() = default;
    ~ITaskAPI() = default;

    virtual Task getTask(const size_t idTask) = 0;
};

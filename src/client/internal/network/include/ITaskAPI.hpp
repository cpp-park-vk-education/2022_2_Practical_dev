#pragma once

#include "Task.hpp"

class ITaskAPI {
 public:
    ITaskAPI();

    virtual Task getTask(const size_t idTask) = 0;
};

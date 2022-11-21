#pragma once

#include "ITaskAPI.hpp"

class ImplTaskAPI: public ITaskAPI {
 public:
    ImplTaskAPI();

    virtual Task getTask(const size_t idTask);
};

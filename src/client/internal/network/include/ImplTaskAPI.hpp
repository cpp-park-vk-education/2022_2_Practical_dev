#pragma once

#include "ITaskAPI.hpp"

class ImplTaskAPI: public ITaskAPI {
 public:
    ImplTaskAPI();
    ~ImplTaskAPI();

    Task getTask(const size_t idTask) override;
};

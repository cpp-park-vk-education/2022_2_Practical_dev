#pragma once

#include "CheckerResult.hpp"
#include "Container.hpp"
#include "TaskConfig.hpp"
#include "RunnerCommon.h"
#include "SocketCRUD.hpp"

class Runner {
 private:
    std::string host = "localhost";
    std::string port = "80";
    SocketCRUD crud;

 public:
    Runner();
    ~Runner();

    virtual CheckerResult Run(const size_t& task_id, const std::string& code, const std::string& language);
};

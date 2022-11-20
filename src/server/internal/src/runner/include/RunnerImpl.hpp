#pragma once

#include "CheckerResultImpl.hpp"
#include "CheckerResult.hpp"
#include "Container.hpp"
#include "TaskConfig.hpp"
#include "RunnerCommon.h"
#include "SocketCRUD.hpp"

class RunnerImpl {
 private:
    std::string host = "localhost";
    std::string port = "80";
    SocketCRUD crud;

 public:
    RunnerImpl();
    ~RunnerImpl();

    CheckerResult Run(const size_t& task_id, const std::string& code, const std::string& language);
};

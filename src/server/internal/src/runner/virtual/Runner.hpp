#pragma once

#include "CheckerResult.hpp"
#include "Image.hpp"
#include "RunConfig.hpp"
#include "RunnerCommon.h"
#include "SocketCRUD.hpp"
#include "TaskConfig.hpp"

class Runner {
 private:
    std::string host = "localhost";
    std::string port = "80";
    SocketCRUD crud;

 public:
    Runner() = default;
    ~Runner() = default;

    virtual CheckerResult Run(const size_t& task_id, const std::string& code, const RunConfig& subj_conf) = 0;
};

#pragma once

#include "CheckerResult.hpp"
#include "CheckerResultImpl.hpp"
#include "Image.hpp"
#include "RunConfig.hpp"
#include "Runner.hpp"
#include "RunnerCommon.h"
#include "SocketCRUD.hpp"
#include "TaskConfig.hpp"

class RunnerImpl : Runner {
 private:
    std::string host = "localhost";
    std::string port = "80";
    SocketCRUD crud;

 public:
    RunnerImpl();
    ~RunnerImpl();

    CheckerResult Run(const size_t& task_id, const std::string& code, const RunConfig& subj_conf) override;
};

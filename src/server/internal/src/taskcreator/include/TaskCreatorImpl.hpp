#pragma once

#include "RunConfig.hpp"
#include "SocketCRUD.hpp"
#include "TaskCreator.hpp"

class TaskCreatorImpl : TaskCreator {
 private:
    std::string host = "localhost";
    std::string port = "80";
    SocketCRUD crud;

 public:
    TaskCreatorImpl() = default;

    int Setup(const Task& cfg, const RunConfig& sol_conf, const RunConfig& gen_conf) override;

    ~TaskCreatorImpl() = default;
};

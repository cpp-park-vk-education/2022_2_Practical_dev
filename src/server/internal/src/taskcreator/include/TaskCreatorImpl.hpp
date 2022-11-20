#pragma once

#include "Task.hpp"
#include "SocketCRUD.hpp"

class TaskCreatorImpl {
 private:
    std::string host;
    std::string port;
    SocketCRUD crud;

 public:
    TaskCreatorImpl();

    int Setup(const Task& cfg);

    ~TaskCreatorImpl();
};

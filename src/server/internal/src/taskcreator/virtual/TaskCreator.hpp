#pragma once

#include "Task.hpp"

class TaskCreator {
 private:
 public:
    TaskCreator();

    virtual int Setup(const Task& cfg);

    ~TaskCreator();
};

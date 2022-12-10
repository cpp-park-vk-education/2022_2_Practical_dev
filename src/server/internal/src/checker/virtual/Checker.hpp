#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "CheckerResult.hpp"

class Checker {
 private:
    bool foo;

 public:
    Checker() = default;
    virtual CheckerResult RunTests() = 0;
    virtual ~Checker() = default;
};

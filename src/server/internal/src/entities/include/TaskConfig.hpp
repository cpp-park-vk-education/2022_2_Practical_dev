#pragma once

#include <string>

struct TaskConfig {
    std::string language;
    std::string generator;
    std::string solution;
    size_t amount_of_tests;
};

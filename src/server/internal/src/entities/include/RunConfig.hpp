#pragma once

#include <string>

struct RunConfig {
    size_t id;
    std::string name;
    std::string compiler;
    std::string compiler_flags;
    std::string interpreter;
    std::string interpreter_flags;
};

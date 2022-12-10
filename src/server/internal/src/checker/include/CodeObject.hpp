#pragma once

#include <string>

#include "Compiler.hpp"
#include "Interpreter.hpp"

struct CodeObject {
    Compiler compiler;
    Interpreter interpreter;

    std::string path_to_source;
    std::string path_to_output;

    bool is_compilation_needed = false;
};

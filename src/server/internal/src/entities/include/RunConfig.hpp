#pragma once

#include <istream>
#include <string>

struct RunConfig {
    size_t id;
    std::string name;
    std::string compiler;
    std::string compiler_flags;
    std::string interpreter;
    std::string interpreter_flags;

    bool operator==(const RunConfig& rhs) const {
        return name == rhs.name;
    }

    friend std::ostream& operator<<(std::ostream& os, const RunConfig& it) noexcept {
        os << /* "compiler = " << */ it.compiler << std::endl;
        os << /* "compiler_flags = " << */ it.compiler_flags << std::endl;
        os << /* "interpreter = " << */ it.interpreter << std::endl;
        os << /* "interpreter_flags = " << */ it.interpreter_flags << std::endl;
        return os;
    }
};

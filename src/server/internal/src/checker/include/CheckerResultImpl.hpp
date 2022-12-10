#pragma once

#include <ctime>
#include <istream>
#include <string>

#include "CheckerResult.hpp"

enum class _checkererror {
    OK,
    WA,
    CE,
    TL,
    ML,
    RE,
    NE
};

struct CheckerResultImpl : public CheckerResult {
    _checkererror code;
    float run_memory;
    std::time_t run_time;
    size_t failed_test;
    size_t points;

    CheckerResultImpl(_checkererror code, std::string message) : code(code) { this->message = message; }

    friend std::ostream& operator<<(std::ostream& stream, const CheckerResultImpl& obj) {
        stream << obj.message << std::endl;
        return stream;
    }

    bool operator==(const CheckerResultImpl& rhs) {
        return code == rhs.code;
    }

    static CheckerResult OK() {
        return CheckerResultImpl(_checkererror::OK, "OK");
    }

    static CheckerResult CE() {
        return CheckerResultImpl(_checkererror::CE, "Compilation error");
    }

    static CheckerResult NE() {
        return CheckerResultImpl(_checkererror::NE, "Not compiled error");
    }

    static CheckerResult WA(const std::string& test_num) {
        return CheckerResultImpl(_checkererror::WA, "Wrong answer on test " + test_num);
    }
};

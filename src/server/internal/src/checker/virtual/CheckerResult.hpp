#pragma once

#include <iostream>
#include <string>
#include <vector>

struct CheckerResult {
    // _checkererror code;
    std::string message;

    // CheckerResult(_checkererror code, const std::string& message) : code(code), message(message) {}

    friend std::ostream& operator<<(std::ostream& stream, const CheckerResult& obj) {
        stream << obj.message << std::endl;
        return stream;
    }

    bool operator==(const CheckerResult& rhs);

    static CheckerResult OK();

    static CheckerResult CE();

    static CheckerResult NE();

    static CheckerResult WA(const std::string& test_num);
};

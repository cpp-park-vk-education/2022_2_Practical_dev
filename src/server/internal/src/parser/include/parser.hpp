#pragma once

#include "utils/namespaces.hpp"
#include "utils/constants.hpp"

#include <array>

class Parser {
 public:
    void serialize(http::response<http::string_body> &response_, std::array<char, MESSAGE_BUFFER_SIZE> &buffer_);
    void deserialize(std::array<char, MESSAGE_BUFFER_SIZE> &buffer_, http::request<http::string_body> &request_);
};
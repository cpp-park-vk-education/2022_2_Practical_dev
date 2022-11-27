#pragma once

#include "namespaces.hpp"

#include <unordered_map>

class ApiHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};
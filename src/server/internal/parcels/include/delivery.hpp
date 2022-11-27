#pragma once

#include "namespaces.hpp"

#include "api_handler.hpp"

class ParcelGetHandler : ApiHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class ParcelAddHandler : ApiHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};
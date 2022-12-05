#pragma once

#include "namespaces.hpp"
#include "src/router/router.hpp"

class ParcelGetHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class ParcelAddHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

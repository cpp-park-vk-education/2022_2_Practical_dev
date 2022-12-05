#pragma once

#include "namespaces.hpp"
#include "src/router/router.hpp"

class TaskGetHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class TaskGetParcelsHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class TaskGetCommentsHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

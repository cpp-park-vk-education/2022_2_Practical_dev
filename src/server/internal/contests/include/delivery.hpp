#pragma once

#include "namespaces.hpp"
#include "router/router.hpp"

class ContestGetHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class ContestModifyHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class ContestDeleteHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class ContestGetTasksHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class ContestSetTaskHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class ContestDeleteTaskHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class ContestGetUsersHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class ContestAddUserHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class ContestDeleteUserHandler : DeliveryHandler {
 public:
    virtual void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

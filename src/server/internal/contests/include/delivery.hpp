#pragma once

#include "namespaces.hpp"

#include "api_handler.hpp"

class ContestGetHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class ContestModifyHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class ContestDeleteHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class ContestGetTasksHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class ContestSetTaskHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class ContestDeleteTaskHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class ContestGetUsersHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class ContestAddUserHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class ContestDeleteUserHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};
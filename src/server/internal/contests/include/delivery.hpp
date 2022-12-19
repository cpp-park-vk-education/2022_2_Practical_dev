#pragma once

#include "utils/namespaces.hpp"
#include "router/router.hpp"

class ContestGetHandler : public DeliveryHandler {
 public:
    virtual void handle (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response) {
            response.body() = "contests get";
        }

    virtual void handle (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response,
        std::unordered_map<std::string, size_t> params) {
            response.body() = "contests get";
        }
};

class ContestModifyHandler : public DeliveryHandler {
 public:
    virtual void handle (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response) {
            response.body() = "contests modify";
        }

    virtual void handle (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response,
        std::unordered_map<std::string, size_t> params) {
            response.body() = "contests modify";
        }
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

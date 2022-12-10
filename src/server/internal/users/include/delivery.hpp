#pragma once

#include "namespaces.hpp"
#include "src/router/router.hpp"

class UserGetHandler : public DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class UserModifyHandler : public DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class UserContestGetHandler : public DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class UserContestAddHandler : public DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class UserContestDeleteHandler : public DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class SignInHandler : public DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

class SignUpHandler : public DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> request,
        http::response<http::string_body> response,
        std::unordered_map<std::string, size_t> params);
};

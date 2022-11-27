#pragma once

#include "namespaces.hpp"

#include "api_handler.hpp"

class UserGetHandler : public ApiHandler {
 public:
    void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class UserModifyHandler : public ApiHandler {
 public:
    void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class UserContestGetHandler : public ApiHandler {
 public:
    void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class UserContestAddHandler : public ApiHandler {
 public:
    void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class UserContestDeleteHandler : public ApiHandler {
 public:
    void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class SignInHandler : public ApiHandler {
 public:
    void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class SignUpHandler : public ApiHandler {
 public:
    void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};
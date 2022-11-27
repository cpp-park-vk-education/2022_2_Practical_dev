#pragma once

#include "namespaces.hpp"

#include "api_handler.hpp"

class CommentGetHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class CommentAddHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class CommentModifyHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class CommentDeleteHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class CommentBumpHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};

class CommentSageHandler : ApiHandler {
public:
    virtual void operator() (
        http::request<http::string_body> request_,
        http::response<http::string_body> response_,
        std::unordered_map<std::string, size_t> params);
};
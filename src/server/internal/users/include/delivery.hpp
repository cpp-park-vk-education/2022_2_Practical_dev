#pragma once

#include "handler.hpp"

class UserGetHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class UserModifyHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class UserContestGetHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class UserContestAddHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class UserContestDeleteHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class SignInHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class SignUpHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};
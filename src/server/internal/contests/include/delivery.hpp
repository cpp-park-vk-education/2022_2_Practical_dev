#pragma once

#include "handler.hpp"

class ContestGetHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class ContestModifyHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class ContestDeleteHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class ContestGetTasksHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class ContestSetTaskHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class ContestDeleteTaskHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class ContestGetUsersHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class ContestAddUserHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class ContestDeleteUserHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};
#pragma once

#include "handler.hpp"

class TaskGetHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class TaskGetParcelsHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class TaskGetCommentsHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};
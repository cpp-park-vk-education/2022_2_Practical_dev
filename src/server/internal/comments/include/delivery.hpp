#pragma once

#include "handler.hpp"

class CommentGetHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class CommentAddHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class CommentModifyHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class CommentDeleteHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class CommentBumpHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};

class CommentSageHandler : Handler {
    void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)());
};
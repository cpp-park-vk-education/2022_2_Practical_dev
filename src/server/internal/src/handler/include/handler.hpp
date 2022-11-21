#pragma once

#include <boost/beast.hpp>
#include <list>
#include <functional>

namespace http = boost::beast::http;

class Endpoint {
    std::string path;
    http::verb method;
};

class Handler {
    Endpoint ep;

    virtual void operator() (
        http::request<http::string_body> &req,
        http::response<http::string_body> &res,
        void(*callback)()) = 0;
    
    size_t param(std::string name);
};
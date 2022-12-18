#pragma once


#include <map>

#include "namespaces.hpp"
#include "router/router.hpp"
#include "connection/connection.hpp"

class DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response,
        std::unordered_map<std::string, size_t> params);

    DeliveryHandler();
};


template<typename Handler>
class Router : IRouter<Handler> {
    struct target {
        http::verb method_;
        std::string url_;
    };

    std::map<target, Handler> handlers;

 public:
    Router();
    void add_handler(http::verb method, std::string url, Handler handler);
    Handler route(http::verb method, std::string url) override;
};

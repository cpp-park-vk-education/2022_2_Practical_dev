#pragma once


#include <unordered_map>
#include <array>
#include <stack>

#include <mutex>

#include "namespaces.hpp"
#include "router/router.hpp"
#include "connection.hpp"

class DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response,
        std::unordered_map<std::string, size_t> params);

    DeliveryHandler();
};

class RouterPool : IRouterPool {
    struct target {
        http::verb method_;
        std::string url_;
    };

    class Router {
        std::unordered_map<target, DeliveryHandler&> handlers;
        DeliveryHandler& route(http::verb method_, std::string url_);
    };

    std::unordered_map<target, DeliveryHandler&> handlers;

    std::mutex mutex_;
    std::array<Router, 10> routers;
    std::stack<Router&> free_routers;

    Router& get();
    void free(Router &router);

 public:
    RouterPool();
    void add_handler(http::verb method_, std::string url_, DeliveryHandler &handler_);
    DeliveryHandler& route(http::verb method_, std::string url_);
};

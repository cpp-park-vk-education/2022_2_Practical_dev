#pragma once

#include "namespaces.hpp"

#include <unordered_map>
#include <array>
#include <stack>

#include <mutex>

#include "connection.hpp"

class DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response,
        std::unordered_map<std::string, size_t> params
    );

    DeliveryHandler();
};

class Router {
    struct target {
        http::verb method_;
        std::string url_;
    };

    class RouterWorker {
        std::unordered_map<target, DeliveryHandler&> handlers;
        DeliveryHandler& route(http::verb method_, std::string url_);
    };

    std::unordered_map<target, DeliveryHandler&> handlers;

    std::mutex mutex_;
    std::array<RouterWorker, 10> workers;
    std::stack<RouterWorker&> free_workers;

    RouterWorker& get();
    void free(RouterWorker &worker);

 public:
    void add_handler(http::verb method_, std::string url_, DeliveryHandler &handler_);
    DeliveryHandler& route(http::verb method_, std::string url_);
};
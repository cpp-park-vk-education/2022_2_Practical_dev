#pragma once

#include "namespaces.hpp"

#include <unordered_map>
#include <array>
#include <mutex>
#include <utility>

#include "connection.hpp"
#include "api_handler.hpp"

class DeliveryHandler {
    ApiHandler &handler;
 public:
    void operator() (http::request<http::string_body> &request_, http::response<http::string_body> &response_, Connection &conn_);
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
    std::array<std::mutex, 10> worker_mutexes;
    std::array<RouterWorker, 10> workers;
 public:
    void add_handler(http::verb method_, std::string url_, ApiHandler &handler_);
    DeliveryHandler& route(http::verb method_, std::string url_);
};
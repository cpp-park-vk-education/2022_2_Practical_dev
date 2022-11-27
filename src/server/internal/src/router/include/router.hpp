#pragma once

#include "namespaces.hpp"

#include <unordered_map>
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
    std::unordered_map<std::pair<http::verb, std::string>, DeliveryHandler> handlers;
 public:
    void add_handler(http::verb method_, std::string target_, ApiHandler &handler_);
    DeliveryHandler& route(http::verb method_, std::string target_);
};
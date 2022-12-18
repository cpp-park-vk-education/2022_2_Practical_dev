#pragma once

#include <map>

#include "utils/namespaces.hpp"
#include "router/router.hpp"
#include "connection/connection.hpp"

class DeliveryHandler {
 public:
    void operator() (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response,
        std::unordered_map<std::string, size_t> params);

    DeliveryHandler() = default;
};

struct target {
    http::verb method_;
    std::string url_;

    bool operator<(const target &other) const {
        if (this->method_ != other.method_)
            return this->method_ < other.method_;

        return this->url_ < other.url_;
    }
};

template<typename Handler>
class Router : IRouter<Handler> {
    using handler_type = Handler;

    std::map<target, handler_type> handlers;

 public:
    Router();
    void add_handler(http::verb method, std::string url, handler_type handler);
    handler_type route(http::verb method, std::string url) override;
};

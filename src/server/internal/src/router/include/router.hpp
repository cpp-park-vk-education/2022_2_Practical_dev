#pragma once

#include <map>
#include <memory>

#include "utils/namespaces.hpp"
#include "router/router.hpp"

class DeliveryHandler {
 public:
    virtual void handle (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response) = 0;
    virtual void handle (
        http::request<http::string_body> &request,
        http::response<http::string_body> &response,
        std::unordered_map<std::string, size_t> params) = 0;

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
class Router : public IRouter<Handler> {
    using handler_type = Handler;

    std::map<target, Handler> handlers;

 public:
    Router();
    void add_handler(http::verb method, std::string url, Handler handler);
    Handler route(http::verb method, std::string url) override;
};

template<typename Handler>
Handler Router<Handler>::route(http::verb method, std::string url) {
    return this->handlers[{method, url}];
}

template<typename Handler>
Router<Handler>::Router() : handlers() {}

template<typename Handler>
void Router<Handler>::add_handler(http::verb method, std::string url, Handler handler) {
    this->handlers[{method, url}] = handler;
}
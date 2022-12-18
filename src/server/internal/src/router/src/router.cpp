#include <memory>

#include "utils/namespaces.hpp"
#include "router/router.hpp"

template<>
Router<std::shared_ptr<DeliveryHandler>>::handler_type Router<std::shared_ptr<DeliveryHandler>>::route(http::verb method, std::string url) {}

template<>
Router<std::shared_ptr<DeliveryHandler>>::Router() : handlers() {}

template<>
void Router<std::shared_ptr<DeliveryHandler>>::add_handler(http::verb method, std::string url, handler_type handler) {
    this->handlers[{method, url}] = handler;
}
#include <memory>

#include "router/router.hpp"

template<>
std::shared_ptr<DeliveryHandler> Router<std::shared_ptr<DeliveryHandler>>::route(http::verb method, std::string url) {}
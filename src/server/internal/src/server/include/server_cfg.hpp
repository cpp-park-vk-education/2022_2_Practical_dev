#pragma once

#include "namespaces.hpp"

struct ServerConfig {
    asio::io_context ioc;
    tcp::endpoint ep;
};
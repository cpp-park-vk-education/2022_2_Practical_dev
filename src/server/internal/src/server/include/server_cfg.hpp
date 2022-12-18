#pragma once

#include "utils/namespaces.hpp"

struct ServerConfig {
    asio::io_context ioc;
    tcp::endpoint ep;

    ServerConfig();
    ServerConfig(const ServerConfig &other);
};

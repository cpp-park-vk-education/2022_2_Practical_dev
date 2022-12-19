#pragma once

#include <memory>

#include "server/server.hpp"
#include "acceptor/acceptor.hpp"
#include "router/router.hpp"

class Server : IServer {
    asio::io_context &io_context;
    Router<DeliveryHandler*> router;
    Acceptor acceptor;

 public:
    Server(asio::io_context &ioc, tcp::endpoint ep);

    void run();
    void stop();
};

#pragma once

#include "server/server.hpp"
#include "acceptor/acceptor.hpp"

class Server : IServer {
    asio::io_context &io_context;
    Acceptor acceptor;
 public:
    Server(asio::io_context &ioc, tcp::endpoint ep);
    void run();
    void stop();
};

#include "namespaces.hpp"
#include "server/server.hpp"
#include "acceptor/acceptor.hpp"
#include "connection_manager/connection_manager.hpp"

Server::Server(asio::io_context &ioc, tcp::endpoint ep) : io_context(ioc), acceptor(ioc, ep) {}

void Server::run() {
    this->acceptor.accept();
}

void Server::stop() {}
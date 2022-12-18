#include <memory>

#include "namespaces.hpp"
#include "server/server.hpp"
#include "acceptor/acceptor.hpp"
#include "connection_manager/connection_manager.hpp"

#include "contests/contests.hpp"

Server::Server(asio::io_context &ioc, tcp::endpoint ep) : io_context(ioc), router(), acceptor(ioc, ep) {
    router.add_handler(http::verb::get, "/contests", std::make_shared<DeliveryHandler>(ContestGetHandler()));
}

void Server::run() {
    this->acceptor.accept();
}

void Server::stop() {}
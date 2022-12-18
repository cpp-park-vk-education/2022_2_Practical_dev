#include <memory>

#include "utils/namespaces.hpp"

#include "server/server.hpp"
#include "acceptor/acceptor.hpp"
#include "router/router.hpp"

#include "contests/contests.hpp"

Server::Server(asio::io_context &ioc, tcp::endpoint ep) : io_context(ioc), router(), acceptor(ioc, ep) {
    router.add_handler(http::verb::get, "/contests", std::shared_ptr<DeliveryHandler>(new ContestGetHandler()));
}

void Server::run() {
    this->acceptor.accept();
}

void Server::stop() {}
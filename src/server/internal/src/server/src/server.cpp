#include <memory>

#include "utils/namespaces.hpp"

#include "server/server.hpp"
#include "acceptor/acceptor.hpp"
#include "router/router.hpp"

#include "contests/contests.hpp"

Server::Server(asio::io_context &ioc, tcp::endpoint ep) : io_context(ioc), router(), acceptor(ioc, ep, router) {
    router.add_handler(http::verb::get, "/contests", new ContestGetHandler());
    router.add_handler(http::verb::post, "/contests", new ContestModifyHandler());
}

void Server::run() {
    this->acceptor.accept();
}

void Server::stop() {}
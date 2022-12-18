#pragma once

#include "utils/namespaces.hpp"
#include "acceptor/acceptor.hpp"

class Acceptor : IAcceptor {
    asio::io_context &io_context;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void on_accept(beast::error_code ec, tcp::socket socket);
    void do_accept();

 public:
    void accept();
    Acceptor(asio::io_context &ioc, tcp::endpoint ep);
};

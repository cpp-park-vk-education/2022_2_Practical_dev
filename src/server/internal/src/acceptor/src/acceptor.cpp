#include "utils/namespaces.hpp"
#include "acceptor/acceptor.hpp"
#include "connection/connection.hpp"

#include <memory>

Acceptor::Acceptor(asio::io_context &ioc, tcp::endpoint ep) : io_context(ioc), endpoint(ep), acceptor(ioc) {
    acceptor.open(this->endpoint.protocol());
    acceptor.set_option(tcp::acceptor::reuse_address(true));
    acceptor.bind(this->endpoint);
    acceptor.listen();
}

void Acceptor::accept() {
    this->do_accept();
}

void Acceptor::on_accept(beast::error_code ec, tcp::socket socket) {
    if (ec)
        return;

    std::make_shared<Connection>(
        std::move(socket)
    )->start();
    
    this->accept();
}

void Acceptor::do_accept() {
    this->acceptor.async_accept(
        this->io_context,
        beast::bind_front_handler(
            &Acceptor::on_accept,
            this
        )
    );
}

#include "namespaces.hpp"
#include "connection/connection.hpp"

#include <utility>

Connection::Connection(tcp::socket &&socket) : stream(std::move(socket)) {}

void Connection::do_read() {
    this->request = {};

    http::async_read(
        this->stream,
        this->buffer,
        this->request,
        beast::bind_front_handler(
            &Connection::on_read,
            this->shared_from_this()
        )
    );
}

void Connection::on_read(beast::error_code, size_t bytes_transferred) {
    http::response<http::string_body> response;

    response.version(11);
    response.result(http::status::ok);
    response.body() = "\nHello?\n";

    this->do_write();
}

void Connection::do_write() {
    http::async_write(
        this->stream,
        std::move(response),
        beast::bind_front_handler(
            &Connection::on_write,
            this->shared_from_this()
        )
    );
}

void Connection::on_write(beast::error_code, size_t bytes_transferred) {
    this->stop();
}

void Connection::stop() {
    this->stream.socket().shutdown(tcp::socket::shutdown_send);
}

void Connection::start() {
    this->do_read();
}
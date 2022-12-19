#include <iostream>

#include "utils/namespaces.hpp"
#include "connection/connection.hpp"
#include "router/router.hpp"

#include <utility>

Connection::Connection(tcp::socket &&socket, Router<DeliveryHandler*> &router) : stream(std::move(socket)), router(router) {}

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
    this->response = {};
    this->response.version(11);
    this->response.result(http::status::ok);

    this->router.route(this->request.method(), std::string(this->request.target()))->handle(this->request, this->response);

    this->do_write();
}

void Connection::do_write() {
    // http::response<http::string_body> response(this->response);
    http::async_write(
        this->stream,
        this->response,
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
#pragma once

#include <memory>
#include <array>

#include "namespaces.hpp"
#include "constants.hpp"
#include "connection/connection.hpp"

class Connection : public IConnection, public std::enable_shared_from_this<Connection> {
    beast::tcp_stream stream;
    beast::flat_buffer buffer;

    http::response<http::string_body> response;
    http::request<http::string_body> request;

    void on_read(beast::error_code ec, size_t bytes_transferred);
    void on_write(beast::error_code ec, size_t bytes_transferred);

 public:
    void start();
    void stop();

    // void read();
    // void write();

    explicit Connection(tcp::socket &&socket);
};

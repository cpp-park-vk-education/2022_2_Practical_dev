#pragma once

#include "namespaces.hpp"
#include "constants.hpp"

#include <array>

#include "parser.hpp"

class Connection {
    std::array<char, MESSAGE_BUFFER_SIZE> buffer;
    tcp::socket &socket_;

    http::response<http::string_body> response_;
    http::request<http::string_body> request_;

    Parser parser;

 public:
    void start();
    void stop();

    void read();
    void write();

    Connection(tcp::socket &socket_);
};
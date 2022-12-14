#pragma once

#include "acceptor/acceptor.hpp"
#include "server_cfg.hpp"
#include "connection_manager/connection_manager.hpp"

class Server {
    ServerConfig cfg_;
    Acceptor acceptor_;
    ConnectionManager conn_manager_;

 public:
    explicit Server(const ServerConfig& cfg);

    void run();
    void accept();
    void stop();
};

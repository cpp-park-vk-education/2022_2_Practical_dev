#pragma once

#include <set>
#include "connection/connection.hpp"

class ConnectionManager {
    std::set<Connection> conns_;
 public:
    void start(Connection &conn_);
    void stop(Connection &conn_);

    ConnectionManager();
};

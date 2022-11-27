#pragma once

#include <set>
#include "connection.hpp"

class ConnectionManager {
    std::set<Connection> conns_;
 public:
    void start();
    void stop();

    ConnectionManager();
};
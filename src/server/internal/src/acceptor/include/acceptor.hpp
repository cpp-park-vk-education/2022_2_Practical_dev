#pragma once

#include "namespaces.hpp"

class Acceptor {
 public:
    tcp::socket& listen();
    explicit Acceptor(const tcp::endpoint& ep);
};

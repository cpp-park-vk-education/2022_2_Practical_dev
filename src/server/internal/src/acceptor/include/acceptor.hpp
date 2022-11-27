#pragma once

#include "namespaces.hpp"

class Acceptor {
 public:
    tcp::socket& listen();
    Acceptor(const tcp::endpoint& ep);
};
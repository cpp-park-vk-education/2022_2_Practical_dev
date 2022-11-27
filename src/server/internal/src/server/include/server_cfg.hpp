#pragma once

#include "namespaces.hpp"

class ServerConfig { 
 public:
    asio::io_context ioc;
    tcp::endpoint ep;
    std::string doc_root;
    // etc...
};
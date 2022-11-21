#pragma once

#include "listener.hpp"

class ServerConfig {};

class Server {
    Listener listener;

    void init(const ServerConfig &cfg);
    void run();
};
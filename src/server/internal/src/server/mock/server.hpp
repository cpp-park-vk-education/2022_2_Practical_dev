#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "utils/namespaces.hpp"

class ClientMock {
    asio::io_context &ioc_;
    std::string sd_;
    std::string ed_;
    std::string rd_;

 public:
    ClientMock(asio::io_context &ioc);
    void send(
        std::string host,
        std::string port,
        http::verb verb,
        std::string target,
        unsigned version,
        std::string send_data
        );

    void recieve();
    bool check();
};
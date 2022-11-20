#pragma once

#include "RunnerCommon.h"

using boost::asio::local::stream_protocol;

class SocketCRUD {
 private:
    boost::asio::io_context io_context;
    stream_protocol::socket s;
    int version = 11;

 public:
    SocketCRUD();
    explicit SocketCRUD(const std::string& endpoint);
    SocketCRUD(const SocketCRUD& obj);
    json GET(const std::string& host, const std::string& target);
    json POST(const std::string& host, const std::string& target, json data = json());
    json DELETE(const std::string& host, const std::string& target, json data = json());
    ~SocketCRUD();
};

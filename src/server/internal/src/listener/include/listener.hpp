#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>

namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;

class Listener {
    net::io_context ioc;
    tcp::endpoint ep;
    tcp::acceptor acceptor;

    void listen(tcp::socket &sock);
};
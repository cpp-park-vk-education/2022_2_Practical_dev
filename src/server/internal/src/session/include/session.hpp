#pragma once

#include <boost/asio.hpp>

using tcp = boost::asio::ip::tcp;

class Session {
    tcp::socket sock;

    template<typename Stream>
    void recieve(Stream &stream, std::string_view buf);

    template<typename Stream>
    void send(Stream &stream, std::string_view buf);

    void run();
    
    void close();
};
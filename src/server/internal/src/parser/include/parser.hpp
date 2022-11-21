#pragma once

#include <boost/beast.hpp>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;

class Parser {
    template<typename Body, typename Allocator>
    void deserialize(char *buf, http::request<Body, http::basic_fields<Allocator>> *req);

    template<typename Body, typename Allocator>
    void serialize(http::response<Body, http::basic_fields<Allocator>> *res, char *buf);
};
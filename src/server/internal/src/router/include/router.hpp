#pragma once

#include <boost/beast.hpp>
#include <vector>

#include "parser.hpp"
#include "handler.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class Router {
    std::vector<Handler> hs;

    void route(http::request<http::string_body> req, http::response<http::string_body> res);

    void addHandler(Handler &handler_func);
    Handler& getHandler(Endpoint ep);
};
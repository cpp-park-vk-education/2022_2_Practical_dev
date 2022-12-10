#pragma once

#include <boost/asio.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast.hpp>

namespace asio = boost::asio;
namespace ip = asio::ip;
using tcp = asio::ip::tcp;

namespace beast = boost::beast;
namespace http = beast::http;

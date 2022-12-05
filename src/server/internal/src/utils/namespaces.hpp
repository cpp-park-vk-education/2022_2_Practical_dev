#pragma once

#include <boost/asio.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast.hpp>

namespace asio = boost::asio;
using tcp = asio::ip::tcp;

namespace beast = boost::beast;
namespace http = beast::http;

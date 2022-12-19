#include "namespaces.hpp"
#include "server/mock/server.hpp"

ClientMock::ClientMock(asio::io_context &ioc) :
    ioc_(ioc),
    sd_(),
    ed_(),
    rd_() {}

void ClientMock::send(
    std::string host,
    std::string port, 
    http::verb verb,
    std::string target,
    unsigned version,
    std::string send_data
) {

    tcp::resolver resolver(this->ioc_);
    auto const results = resolver.resolve(host, port);

    beast::tcp_stream stream(this->ioc_);
    stream.connect(results);

    http::request<http::string_body> request(verb, target, version);
    request.set(http::field::host, host);

    request.body() = send_data;

    http::write(stream, request);
}
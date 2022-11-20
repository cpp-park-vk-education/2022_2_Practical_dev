/* #pragma once

#include "RunnerCommon.h"

boost::asio::io_context io_context;
using boost::asio::local::stream_protocol;

stream_protocol::socket s(io_context);

json socket_POST(const std::string& host,
                 const std::string& target, json data = json()) {
    int version = 11;

    auto msg = data.dump();

    http::request<http::string_body> req{http::verb::post, target, version};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::accept, "");
    req.set(http::field::content_type, "application/json");
    req.set(http::field::content_length, boost::lexical_cast<std::string>(msg.length()));
    req.body() = msg;

    // Send the HTTP request to the remote host
    http::write(s, req);

    // This buffer is used for reading and must be persisted
    beast::flat_buffer buffer;

    // Declare a container to hold the response
    http::response<http::dynamic_body> res;

    // Receive the HTTP response
    http::read(s, buffer, res);

    // Write the message to standard out
    // std::cout << res << std::endl;
    std::string buf_str = beast::buffers_to_string(res.body().data());
    auto ans = buf_str != "" ? json::parse(buf_str) : json();

    return ans;
}

std::string socket_GET(const std::string& host, const std::string& target) {
    int version = 11;

    http::request<http::string_body> req{http::verb::get, target, version};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::accept, "application/json");

    // Send the HTTP request to the remote host
    http::write(s, req);

    // This buffer is used for reading and must be persisted
    beast::flat_buffer buffer;

    // Declare a container to hold the response
    http::response<http::dynamic_body> res;

    // Receive the HTTP response
    http::read(s, buffer, res);

    // Write the message to standard out
    // std::cout << res << std::endl;
    std::string buf_str = beast::buffers_to_string(res.body().data());
    // auto ans = buf_str != "" ? json::parse(buf_str) : json();

    return buf_str;
}

json socket_DELETE(const std::string& host,
                   const std::string& target, json data = json()) {
    int version = 11;

    auto msg = data.dump();

    http::request<http::string_body> req{http::verb::delete_, target, version};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::accept, "");
    req.set(http::field::content_type, "application/json");
    req.set(http::field::content_length, boost::lexical_cast<std::string>(msg.length()));
    req.body() = msg;

    // Send the HTTP request to the remote host
    http::write(s, req);

    // This buffer is used for reading and must be persisted
    beast::flat_buffer buffer;

    // Declare a container to hold the response
    http::response<http::dynamic_body> res;

    // Receive the HTTP response
    http::read(s, buffer, res);

    // Write the message to standard out
    // std::cout << res << std::endl;
    std::string buf_str = beast::buffers_to_string(res.body().data());
    auto ans = buf_str != "" ? json::parse(buf_str) : json();

    return ans;
}

int setup() {
    std::string host = "localhost";
    std::string port = "80";
    std::string target = "/v1.41/containers/create";

    filesystem::ifstream codeReader("misc/main.cpp");
    std::string buf = "";
    std::string line = "";
    while (getline(codeReader, line)) {
        buf += (line + "\n");
    }

    json data = {
        {"Image", "runner"},
    };
    data["Cmd"] = {"/bin/sh", "-c", "echo '" + buf + std::string("' > main.cpp && ./run.sh")};

    s.connect("/var/run/docker.sock");

    auto ans = socket_POST(host, target, data);
    std::cout << ans << std::endl;

    std::string id_str = ans["Id"].dump();
    target = "/v1.41/containers/" + id_str.substr(1, id_str.length() - 2) + std::string("/start");
    ans = socket_POST(host, target);

    // std::cout << ans << std::endl;

    target = "/v1.41/containers/" + id_str.substr(1, id_str.length() - 2) + std::string("/wait");
    ans = socket_POST(host, target);

    // std::cout << ans << std::endl;

    target = "/v1.41/containers/" + id_str.substr(1, id_str.length() - 2) + std::string("/logs?stdout=true");
    std::string anss = socket_GET(host, target);

    std::cout << anss << std::endl;

    target = "/v1.41/containers/" + id_str.substr(1, id_str.length() - 2);
    ans = socket_DELETE(host, target);

    if (!ans.empty())
        std::cout << anss << std::endl;

    return 0;
}
 */
#include "SocketCRUD.hpp"

SocketCRUD::SocketCRUD() : s(io_context) {
    s.connect("/var/run/docker.sock");
}

SocketCRUD::SocketCRUD(const std::string& endpoint) : s(io_context) {
    s.connect(endpoint);
}

json SocketCRUD::GET(const std::string& host, const std::string& target) {
    http::request<http::string_body> req{http::verb::get, target, version};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    http::write(s, req);

    beast::flat_buffer buffer;

    http::response<http::dynamic_body> res;

    http::read(s, buffer, res);

    std::string content_type;
    try {
        // content_type = res.at("Content-type").data();
    } catch (const std::exception& e) {
        // std::cerr << e.what() << '\n';
        content_type = "plain/text";
    }

    json ans;
    std::string buf_str = beast::buffers_to_string(res.body().data());
    if (content_type == "application/json") {
        ans = buf_str != "" ? json::parse(buf_str) : json();
    } else {
        ans = buf_str;
    }
    return ans;
}

json SocketCRUD::POST(const std::string& host, const std::string& target, json data) {
    auto msg = data.dump();

    http::request<http::string_body> req{http::verb::post, target, version};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::accept, "*/*");
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

json SocketCRUD::DELETE(const std::string& host, const std::string& target, json data) {
    auto msg = data.dump();

    http::request<http::string_body> req{http::verb::delete_, target, version};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.set(http::field::accept, "*/*");
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

SocketCRUD::~SocketCRUD() {
}

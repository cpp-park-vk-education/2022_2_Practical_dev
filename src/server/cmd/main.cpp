#include <iostream>

// #include "Checker.hpp"
// #include "Runner.hpp"
// #include "RunnerImpl.hpp"
#include "utils/namespaces.hpp"
#include "server/server.hpp"

int main() {
    std::cout << "Hello, Server!" << std::endl;

    asio::io_context ioc;

    Server srv{ioc, {ip::make_address("0.0.0.0"), 8888}};
    srv.run();
    ioc.run();

    // RunnerImpl runner;
    // runSubject("10 11\n");
    // runner.Run(10, "#include <iostream>\n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << std::endl;\n    return 0;\n}\n", "c++");  //NOLINT
    return 0;
}

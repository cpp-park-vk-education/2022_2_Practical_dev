#include <iostream>

#include "Checker.hpp"
#include "Runner.hpp"
#include "RunnerImpl.hpp"

int main() {
    std::cout << "Hello, Server!" << std::endl;
    RunnerImpl runner;
    // runSubject("10 11\n");
    runner.Run(10, "#include <iostream>\n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << std::endl;\n    return 0;\n}\n", "c++");  //NOLINT
    return 0;
}

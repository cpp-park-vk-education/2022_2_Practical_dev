#include <gtest/gtest.h>

#include "RunnerImpl.hpp"

TEST(RunnerTest, RunnerRun) {
    RunnerImpl runner;
    // runSubject("10 11\n");
    RunConfig conf;
    conf.name = "c++";
    conf.compiler = "g++";
    conf.compiler_flags = "-omain.out";
    conf.interpreter = "./";
    conf.interpreter_flags = "main.out";
    EXPECT_NO_THROW(runner.Run(10, "#include <iostream>\n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << std::endl;\n    return 0;\n}\n", conf));  //NOLINT
}

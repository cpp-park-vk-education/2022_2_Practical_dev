#include <gtest/gtest.h>

#include "RunnerImpl.hpp"

TEST(RunnerTest, DISABLED_RunnerRun) {
    RunnerImpl runner;
    // runSubject("10 11\n");

    EXPECT_NO_THROW(runner.Run(10, "#include <iostream>\n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << std::endl;\n    return 0;\n}\n", "c++"));  //NOLINT
}

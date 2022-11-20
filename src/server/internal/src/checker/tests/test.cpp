#include <gtest/gtest.h>

#include "CheckerImpl.hpp"

TEST(CheckerTest, Basework) {
    Compiler cmp;
    cmp.compiler = "g++";
    Interpreter intr;
    intr.interpreter = "./";
    CodeObject subj;
    cmp.flags = "--std=c++17 -omain.out";
    subj.compiler = cmp;
    subj.interpreter = intr;
    subj.path_to_source = "misc/main.cpp";
    subj.path_to_output = "main.out";

    CodeObject sol;
    cmp.flags = "--std=c++17 -osolution.out";
    sol.compiler = cmp;
    sol.interpreter = intr;
    sol.path_to_source = "misc/solution.cpp";
    sol.path_to_output = "solution.out";

    CodeObject gen;
    cmp.flags = "--std=c++17 -ogen_test.out";
    gen.compiler = cmp;
    gen.interpreter = intr;
    gen.path_to_source = "misc/gen_test.cpp";
    gen.path_to_output = "gen_test.out";

    CheckerImpl chk(subj, sol, gen);
    chk.GenerateTests(10);
    std::cout << chk.RunTests().message << std::endl
              << "cpp test done\n";
}

#include "Checker.hpp"

#include <fstream>
#include <iostream>

#include "CheckerBuilder.hpp"
#include "CheckerImpl.hpp"

int main() {
    CodeObject sol;
    CodeObject gen;
    CodeObject subj;

    {
        Compiler cmp;
        Interpreter intr;

        std::ifstream sol_conf("/project/sol.conf");

        sol_conf >> cmp.compiler;
        sol_conf >> cmp.flags;
        sol_conf >> intr.interpreter;
        sol_conf >> intr.flags;

        sol_conf.close();

        sol.compiler = cmp;
        sol.interpreter = intr;
        if (cmp.compiler == "g++") {
            sol.path_to_source = "solution.cpp";
        }
        if (cmp.compiler == "javac") {
            sol.path_to_source = "Solution.java";
        }
        if (cmp.compiler == "python") {
            sol.path_to_source = "";
        }
    }

    {
        Compiler cmp;
        Interpreter intr;

        std::ifstream gen_conf("/project/gen.conf");

        gen_conf >> cmp.compiler;
        gen_conf >> cmp.flags;
        gen_conf >> intr.interpreter;
        gen_conf >> intr.flags;

        gen_conf.close();

        gen.compiler = cmp;
        gen.interpreter = intr;
        if (cmp.compiler == "g++") {
            gen.path_to_source = "gen_test.cpp";
        }
        if (cmp.compiler == "javac") {
            gen.path_to_source = "Gen_test.java";
        }
        if (cmp.compiler == "python") {
            gen.path_to_source = "";
        }
    }

    {
        Compiler cmp;
        Interpreter intr;

        cmp.compiler = getenv("SUBJECT_COMPILER");
        cmp.flags = getenv("SUBJECT_COMPILER_FLAGS");
        intr.interpreter = getenv("SUBJECT_INTERPRETER");
        intr.flags = getenv("SUBJECT_INTERPRETER_FLAGS");

        subj.compiler = cmp;
        subj.interpreter = intr;
        if (cmp.compiler == "g++") {
            subj.path_to_source = "main.cpp";
        }
        if (cmp.compiler == "javac") {
            subj.path_to_source = "Main.java";
        }
        if (cmp.compiler == "python") {
            subj.path_to_source = "";
        }
    }

    CheckerImpl chk(subj, sol, gen);
    chk.GenerateTests(10);
    std::cout << chk.RunTests().message << std::endl
              << "cpp test done\n";

    // cmp.compiler = "javac";
    // intr.interpreter = "java";
    // cmp.flags = "-d .";
    // subj.compiler = cmp;
    // subj.interpreter = intr;
    // subj.path_to_source = "misc/Main.java";
    // subj.path_to_output = "Main";

    // CheckerImpl chk2(subj, sol, gen);
    // chk2.GenerateTests(10);
    // std::cout << chk2.RunTests().message << std::endl
    //           << "java test done\n";
}

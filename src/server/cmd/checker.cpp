#include "Checker.hpp"

#include "CheckerBuilder.hpp"
#include "CheckerImpl.hpp"

int main() {
    /* Checker chk("g++", "--std=c++17");
    std::cout << chk.CompileSubject("misc/main.cpp", "main.out", "-omain.out");
    std::cout << chk.CompileSolution("misc/solution.cpp", "solution.out", "-osolution.out");
    std::cout << chk.CompileGenerator("misc/gen_test.cpp", "gen_test.out", "-ogen_test.out");
    std::cout << chk.GenerateTests("tests/", 3);
    std::cout << chk.RunTests(); */
    /* CheckerImpl chk = CheckerBuilder()
    .addGeneratorCompilator("g++", "-ogen_test.out")
    .a
    .build(); */
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

    cmp.compiler = "javac";
    intr.interpreter = "java";
    cmp.flags = "-d .";
    subj.compiler = cmp;
    subj.interpreter = intr;
    subj.path_to_source = "misc/Main.java";
    subj.path_to_output = "Main";

    CheckerImpl chk2(subj, sol, gen);
    chk2.GenerateTests(10);
    std::cout << chk2.RunTests().message << std::endl
              << "java test done\n";
}

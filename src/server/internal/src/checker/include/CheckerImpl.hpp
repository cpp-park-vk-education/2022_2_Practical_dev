#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "CheckerResultImpl.hpp"
#include "Checker.hpp"
#include "CodeObject.hpp"

class CheckerImpl: public Checker {
 private:
    CodeObject subject;
    CodeObject solution;
    CodeObject generator;

    std::vector<std::string> tests;

    CheckerResult compile(const CodeObject& obj);


 public:
    CheckerImpl(const CodeObject& subject, const CodeObject& solution, const CodeObject& generator);

    CheckerResult CompileSubject();
    CheckerResult CompileSolution();
    CheckerResult CompileGenerator();

    CheckerResult GenerateTests(const size_t& testAmount);

    CheckerResult RunTests() override;

    ~CheckerImpl();
};

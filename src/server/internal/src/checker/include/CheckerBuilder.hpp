#pragma once

#include "CheckerImpl.hpp"
#include "CodeObject.hpp"

class CheckerBuilder {
 private:
    CodeObject subject;
    CodeObject solution;
    CodeObject generator;

 public:
    CheckerBuilder();

    CheckerImpl build();

    CheckerBuilder& addSubjectCompilator(const std::string& compiler, const std::string& flags);
    CheckerBuilder& addSubjectCompilator(const Compiler& compiler);

    CheckerBuilder& addSolutionCompilator(const std::string& compiler, const std::string& flags);
    CheckerBuilder& addSolutionCompilator(const Compiler& compiler);

    CheckerBuilder& addGeneratorCompilator(const std::string& compiler, const std::string& flags);
    CheckerBuilder& addGeneratorCompilator(const Compiler& compiler);

    CheckerBuilder& addSubjectInterpreter(const std::string& interpreter, const std::string& flags);
    CheckerBuilder& addSubjectInterpreter(const Interpreter& interpreter);

    CheckerBuilder& addSolutionInterpreter(const std::string& interpreter, const std::string& flags);
    CheckerBuilder& addSolutionInterpreter(const Interpreter& interpreter);

    CheckerBuilder& addGeneratorInterpreter(const std::string& interpreter, const std::string& flags);
    CheckerBuilder& addGeneratorInterpreter(const Interpreter& interpreter);

    CheckerBuilder& addSubjectPaths(const std::string& path_to_source, const std::string& path_to_compiled);
    CheckerBuilder& addSolutionPaths(const std::string& path_to_source, const std::string& path_to_compiled);
    CheckerBuilder& addGeneratorPaths(const std::string& path_to_source, const std::string& path_to_compiled);

    ~CheckerBuilder();
};

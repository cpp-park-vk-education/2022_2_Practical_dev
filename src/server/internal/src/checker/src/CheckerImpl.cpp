#include "CheckerImpl.hpp"

#include <boost/process.hpp>
#include <sstream>

#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS

namespace bp = boost::process;

CheckerImpl::CheckerImpl(const CodeObject& subject, const CodeObject& solution, const CodeObject& generator) : subject(subject), solution(solution), generator(generator) {}  // NOLINT

CheckerImpl::~CheckerImpl() {}

std::vector<std::string> split(const std::string& s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
        // elems.push_back(std::move(item)); // if C++11
    }
    return elems;
}

CheckerResult CheckerImpl::compile(const CodeObject& obj) {
    std::vector<std::string> res = split(obj.compiler.flags + ' ' + obj.path_to_source, ' ');
    if (res[0] == "") {
        res[0] = res[1];
        res.pop_back();
    }
    bp::ipstream errorP;
    boost::filesystem::path p = bp::search_path(obj.compiler.compiler);
    bp::child c(p, bp::args += res, bp::std_err > errorP);
    std::vector<std::string> data;
    std::string line;
    while (std::getline(errorP, line) && !line.empty()) {
        std::cout << line << std::endl;
        data.push_back(line);
    }
    if (!data.empty())
        return CheckerResultImpl::CE();

    return CheckerResultImpl::OK();
}

CheckerResult CheckerImpl::CompileSubject() {
    CheckerResult res = compile(subject);
    return res;
}

CheckerResult CheckerImpl::CompileSolution() {
    CheckerResult res = compile(solution);
    return res;
}

CheckerResult CheckerImpl::CompileGenerator() {
    CheckerResult res = compile(generator);
    return res;
}

CheckerResult CheckerImpl::GenerateTests(const size_t& testAmount) {
    CompileGenerator();
    for (size_t i = 0; i < testAmount; i++) {
        bp::ipstream errorP;
        bp::ipstream outputP;
        boost::filesystem::path p = bp::search_path(generator.interpreter.interpreter);
        bp::child c(p, bp::args = {generator.path_to_output}, bp::std_out > outputP, bp::std_err > errorP);
        std::string line;
        while (std::getline(outputP, line) && !line.empty())
            tests.push_back(line);
    }
    return CheckerResultImpl::OK();
}

CheckerResult CheckerImpl::RunTests() {
    CheckerResult res = CompileSubject();
    if (res.message == "Compilation error") {
        return res;
    }
    CompileSolution();
    for (size_t i = 0; i < tests.size(); i++) {
        bp::opstream inputSubj;
        bp::opstream inputSol;
        bp::ipstream errorSubj;
        bp::ipstream outputSubj;
        bp::ipstream errorSol;
        bp::ipstream outputSol;
        boost::filesystem::path p1 = bp::search_path(solution.interpreter.interpreter);
        bp::child sol(p1, bp::args = {solution.path_to_output}, bp::std_out > outputSol, bp::std_in < inputSol);
        boost::filesystem::path p2 = bp::search_path(subject.interpreter.interpreter);
        bp::child subj(p2, bp::args = {subject.path_to_output}, bp::std_out > outputSubj, bp::std_in < inputSubj);

        inputSol << tests[i] << std::endl;
        inputSubj << tests[i] << std::endl;

        std::vector<std::string> data;
        std::string line;
        while (std::getline(outputSol, line) && !line.empty()) {
            data.push_back(line);
        }

        std::vector<std::string> expected_data;
        while (std::getline(outputSubj, line) && !line.empty()) {
            expected_data.push_back(line);
        }
        if (data != expected_data) {
            return CheckerResultImpl::WA(std::to_string(i + 1));
        }
    }
    return CheckerResultImpl::OK();
}

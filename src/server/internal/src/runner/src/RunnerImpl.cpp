#include "RunnerImpl.hpp"

#include "ImageRepositoryImpl.hpp"
#include "RunConfig.hpp"

RunnerImpl::RunnerImpl() : crud("/var/run/docker.sock") {
}

RunnerImpl::~RunnerImpl() {
}

CheckerResult RunnerImpl::Run(const size_t& task_id, const std::string& code, const RunConfig& subj_conf) {
    std::string target;
    ImageRepositoryImpl repository;
    Image image = repository.SelectByTaskId(task_id);

    json data = {
        {"Image", image.getDockerId()},
    };

    std::string out_file_name = (subj_conf.compiler == "g++" ? "main.cpp" : subj_conf.name == "python" ? "main.py"
                                                                        : subj_conf.name == "java"     ? "Main.class"
                                                                                                       : "main.txt");
    data["Cmd"] = {"/bin/sh", "-c", "echo '" + code + std::string("' > " + out_file_name + " && ./Checker")};
    data["Env"] = {"SUBJECT_LANGUAGE=" + subj_conf.name, "SUBJECT_COMPILER=" + subj_conf.compiler, "SUBJECT_COMPILER_FLAGS=" + subj_conf.compiler_flags, "SUBJECT_INTERPRETER=" + subj_conf.interpreter, "SUBJECT_INTERPRETER_FLAGS=" + subj_conf.interpreter_flags}; //NOLINT

    target = "/v1.41/containers/create";
    std::cout << data << std::endl;
    auto ans = crud.POST(host, target, data);
    std::cout << ans << std::endl;

    std::string id_str = ans["Id"].dump();
    target = "/v1.41/containers/" + id_str.substr(1, id_str.length() - 2) + std::string("/start");
    ans = crud.POST(host, target);

    std::cout << ans << std::endl;

    target = "/v1.41/containers/" + id_str.substr(1, id_str.length() - 2) + std::string("/wait");
    ans = crud.POST(host, target);

    std::cout << ans << std::endl;

    target = "/v1.41/containers/" + id_str.substr(1, id_str.length() - 2) + std::string("/logs?stdout=true");
    ans = crud.GET(host, target);

    std::cout << ans.get<std::string>() << std::endl;

    target = "/v1.41/containers/" + id_str.substr(1, id_str.length() - 2);
    // ans = crud.DELETE(host, target);

    return CheckerResultImpl::OK();
}

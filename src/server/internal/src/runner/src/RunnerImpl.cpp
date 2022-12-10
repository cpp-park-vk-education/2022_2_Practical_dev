#include "RunnerImpl.hpp"

RunnerImpl::RunnerImpl() : crud("/var/run/docker.sock") {
}

RunnerImpl::~RunnerImpl() {
}

CheckerResult RunnerImpl::Run(const size_t& task_id, const std::string& code, const std::string& language) {
    std::string target;

    std::string image = "6851878d802a";

    json data = {
        {"Image", image},
    };
    data["Cmd"] = {"/bin/sh", "-c", "echo '" + code + std::string("' > main.cpp && python3 test.py")};

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

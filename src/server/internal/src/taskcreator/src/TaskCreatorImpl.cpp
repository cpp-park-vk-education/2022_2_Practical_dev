#include "TaskCreatorImpl.hpp"

#include "ImageRepositoryImpl.hpp"
#include "RunConfig.hpp"

int TaskCreatorImpl::Setup(const Task& cfg, const RunConfig& sol_conf, const RunConfig& gen_conf) {
    std::ofstream sol_out("/project/misc/sol.conf");
    sol_out << sol_conf;
    sol_out.close();

    std::ofstream gen_out("/project/misc/gen.conf");
    gen_out << gen_conf;
    gen_out.close();

    system(
        "cd /project/misc && tar -czf ../taskconf.tar.gz solution.* gen_test.*"
        "Dockerfile Checker sol.conf gen.conf");

    boost::filesystem::ifstream tar("/project/taskconf.tar.gz", std::ios::binary);

    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(tar), {});

    std::string tar_str(buffer.begin(), buffer.end());

    json resp = crud.POST(host, "/v1.41/build", tar_str, "application/x-tar");

    std::cout << resp << std::endl;
    std::string docker_id = resp.dump().substr(20, 12);
    std::cout << docker_id << std::endl;
    Image image(cfg.getId(), docker_id);
    ImageRepositoryImpl rep;
    rep.Insert(image);

    return 0;
}

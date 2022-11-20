#include <pqxx/pqxx>

#include "RunConfig.hpp"

class DBRunConfig {
 private:
    pqxx::work worker;

 public:
    DBRunConfig();

    RunConfig Select(const std::string& query);
    std::vector<RunConfig> SelectMany(const std::string& query, size_t n, size_t page = 1);

    RunConfig Insert(const RunConfig& obj);

    RunConfig Update(const RunConfig& obj);

    void Delete(const RunConfig& obj);
};

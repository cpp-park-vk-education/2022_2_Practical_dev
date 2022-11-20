#include <pqxx/pqxx>

#include "Contest.hpp"

class DBContest {
 private:
    pqxx::work worker;

 public:
    DBContest();

    Contest Select(const std::string& query);
    std::vector<Contest> SelectMany(const std::string& query, size_t n, size_t page = 1);

    Contest Insert(const Contest& obj);

    Contest Update(const Contest& obj);

    void Delete(const Contest& obj);
};

#include <pqxx/pqxx>

#include "CodeSource.hpp"

class DBCodeSource {
 private:
    pqxx::work worker;

 public:
    DBCodeSource();

    CodeSource Select(const std::string& query);
    std::vector<CodeSource> SelectMany(const std::string& query, size_t n, size_t page = 1);

    CodeSource Insert(const CodeSource& obj);

    CodeSource Update(const CodeSource& obj);

    void Delete(const CodeSource& obj);
};

#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "CodeSourceRepository.hpp"
#include "DBManager.hpp"

class DBCodeSourceImpl : DBCodeSource {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    DBCodeSourceImpl();

    CodeSource Select(const std::string& query);
    std::vector<CodeSource> SelectMany(const std::string& query, size_t n, size_t page = 1);

    CodeSource Insert(const CodeSource& obj);

    CodeSource Update(const CodeSource& obj);

    void Delete(const CodeSource& obj);
};

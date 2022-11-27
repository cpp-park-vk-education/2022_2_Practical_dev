#pragma once

#include <pqxx/pqxx>

#include "CodeSource.hpp"

class DBCodeSource {
 private:
 public:
    DBCodeSource();

    virtual CodeSource Select(const std::string& query);
    virtual std::vector<CodeSource> SelectMany(const std::string& query, size_t n, size_t page = 1);

    virtual CodeSource Insert(const CodeSource& obj);

    virtual CodeSource Update(const CodeSource& obj);

    virtual void Delete(const CodeSource& obj);
};

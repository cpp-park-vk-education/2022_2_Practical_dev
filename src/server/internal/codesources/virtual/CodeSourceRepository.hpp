#pragma once

#include <pqxx/pqxx>

#include "CodeSource.hpp"

class CodeSourceRepository {
 private:
 public:
    CodeSourceRepository() = default;

    virtual CodeSource Select(const std::string& query) = 0;
    virtual std::vector<CodeSource> SelectMany(const std::string& query, size_t n, size_t page = 1) = 0;

    virtual CodeSource Insert(const CodeSource& obj) = 0;

    virtual CodeSource Update(const CodeSource& obj) = 0;

    virtual void Delete(const CodeSource& obj) = 0;

    ~CodeSourceRepository() = default;
};

#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "CodeSourceRepository.hpp"
#include "DBManager.hpp"

class CodeSourceRepositoryImpl : CodeSourceRepository {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    CodeSourceRepositoryImpl();

    CodeSource Select(const std::string& query) override;
    std::vector<CodeSource> SelectMany(const std::string& query, size_t n, size_t page = 1) override;

    CodeSource Insert(const CodeSource& obj) override;

    CodeSource Update(const CodeSource& obj) override;

    void Delete(const CodeSource& obj) override;
};

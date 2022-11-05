#pragma once

#include <pqxx/pqxx>

#include "DBConnection.hpp"
#include "DBQueryHandler.hpp"

class DBManager {
 private:
 public:
    DBManager();

    pqxx::result Query(const std::string& query, bool commit = false);

    template <typename... Args>
    pqxx::result Query(const std::string& query, bool commit, Args&&... args);

    // ~DBManager();
};

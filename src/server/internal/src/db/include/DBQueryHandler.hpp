#pragma once

#include <pqxx/pqxx>

#include "DBConnection.hpp"

class DBQueryHanlder {
 public:
    template <typename... Args>
    static pqxx::result exec(pqxx::work &worker, const std::string &query, Args &&...args);

    static pqxx::result exec(pqxx::work &worker, const std::string &query);
};

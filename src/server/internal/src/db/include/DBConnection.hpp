#pragma once

#include <pqxx/pqxx>

class DBConnection {
 public:
    static DBConnection& getInstance();
    std::unique_ptr<pqxx::connection> conn;

 private:
    DBConnection();
    ~DBConnection();

 public:
    DBConnection(const DBConnection&) = delete;
    void operator=(const DBConnection&) = delete;
};

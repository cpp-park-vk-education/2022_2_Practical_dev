#ifndef SRC_DB_INCLUDE_DB_HPP_
#define SRC_DB_INCLUDE_DB_HPP_ SRC_DB_INCLUDE_DB_HPP_
#include <pqxx/pqxx>

class DBConnection {
 private:
    pqxx::connection connect;

 public:
    DBConnection();
    ~DBConnection();
};

#endif  // SRC_DB_INCLUDE_DB_HPP_

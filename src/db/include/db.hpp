#include <pqxx/pqxx>

class DBConnection {
private:
  pqxx::connection connect;

public:
  DBConnection();
  ~DBConnection();
};

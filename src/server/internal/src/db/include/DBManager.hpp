#pragma once

#include <pqxx/pqxx>
#include <vector>

class DBManager {
 private:
    std::vector<pqxx::work> workers_pool;

 public:
    DBManager();

    pqxx::work GetFreeWorker();
    void ReturnWorker(pqxx::work& obj);

    ~DBManager();
};

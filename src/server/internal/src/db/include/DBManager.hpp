#pragma once

#include <pqxx/pqxx>
#include <stack>
#include <chrono>
#include <thread>
#include <mutex>

class DBManager {
 private:
    std::vector<std::unique_ptr<pqxx::connection> > connections_pool;
    std::stack<std::unique_ptr<pqxx::work> > workers_pool;
    std::mutex db_mutex;

 public:
    DBManager();

    static DBManager& getInstance();

    std::unique_ptr<pqxx::work> GetFreeWorker();
    void ReturnWorker(std::unique_ptr<pqxx::work> obj);

    DBManager(const DBManager&) = delete;
    void operator=(const DBManager&) = delete;

    ~DBManager() = default;
};

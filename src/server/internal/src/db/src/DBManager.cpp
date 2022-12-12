#include "DBManager.hpp"

#include <iostream>

#include "DBConnection.hpp"

DBManager::DBManager() {
    size_t pool_size = std::atoi(getenv("POOL_SIZE"));

    for (size_t i = 0; i < (size_t)pool_size; i++) {
        connections_pool.push_back(std::make_unique<pqxx::connection>());
        workers_pool.push(std::make_unique<pqxx::work>(*connections_pool[i]));
    }
}

DBManager& DBManager::getInstance() {
    static DBManager instance;

    return instance;
}

std::unique_ptr<pqxx::work> DBManager::GetFreeWorker() {
    std::unique_ptr<pqxx::work> worker(std::move(workers_pool.top()));
    workers_pool.pop();
    return worker;
}

void DBManager::ReturnWorker(std::unique_ptr<pqxx::work> obj) {
    workers_pool.push(std::make_unique<pqxx::work>(*connections_pool[workers_pool.size()]));
}

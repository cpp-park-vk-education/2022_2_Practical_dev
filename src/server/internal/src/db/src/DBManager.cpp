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
    while (!db_mutex.try_lock()) {
        std::this_thread::sleep_for(std::chrono::nanoseconds(100));
    }
    std::unique_ptr<pqxx::work> worker(std::move(workers_pool.top()));
    workers_pool.pop();
    db_mutex.unlock();
    return worker;
}

void DBManager::ReturnWorker(std::unique_ptr<pqxx::work> obj) {
    while (!db_mutex.try_lock()) {
        std::this_thread::sleep_for(std::chrono::nanoseconds(100));
    }
    workers_pool.push(std::make_unique<pqxx::work>(*connections_pool[workers_pool.size()]));
    db_mutex.unlock();
}

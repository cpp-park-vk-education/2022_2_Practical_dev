#include "DBManager.hpp"

#include <iostream>

DBManager::DBManager() {
}

pqxx::result DBManager::Query(const std::string& query, bool commit) {
    pqxx::work worker(*DBConnection::getInstance().conn);
    pqxx::result res = DBQueryHanlder::exec(worker, query);
    if (commit) {
        worker.commit();
    }
    return res;
}

template <typename... Args>
pqxx::result Query(const std::string& query, bool commit, Args&&... args) {
    pqxx::work worker(*DBConnection::getInstance().conn);
    pqxx::result res = DBQueryHanlder::exec(worker, query, args...);
    if (commit) {
        worker.commit();
    }
    return res;
}

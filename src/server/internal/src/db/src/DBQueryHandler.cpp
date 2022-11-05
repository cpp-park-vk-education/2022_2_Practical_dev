#include "DBQueryHandler.hpp"

#include <iostream>

template <typename... Args>
pqxx::result DBQueryHanlder::exec(pqxx::work &worker, const std::string &query, Args &&...args) {
    pqxx::result res;
    try {
        res = worker.exec_params(query, args...);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return res;
}

pqxx::result DBQueryHanlder::exec(pqxx::work &worker, const std::string &query) {
    pqxx::result res;
    try {
        res = worker.exec(query);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return res;
}

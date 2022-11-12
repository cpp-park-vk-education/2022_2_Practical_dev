
#include <DBConnection.hpp>
#include <iostream>

DBConnection::DBConnection() : conn(std::make_unique<pqxx::connection>()) {
}

DBConnection::~DBConnection() {
    conn->disconnect();
}

DBConnection& DBConnection::getInstance() {
    static DBConnection instance;

    return instance;
}

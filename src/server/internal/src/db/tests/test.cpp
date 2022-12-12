#include <gtest/gtest.h>

#include <sstream>

#include "DBConnection.hpp"
#include "DBManager.hpp"

TEST(DBConnectionTest, DISABLED_BaseWork) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::result response = worker->exec("SELECT * FROM users");
    for (size_t i = 0; i < response.size(); i++) {
        std::cout << "id: " << response[i][0] << " Username: " << response[i][1]
                  << " Password: " << response[i][2]
                  << " Email: " << response[i][3] << std::endl;
    }
    DBManager::getInstance().ReturnWorker(std::move(worker));
}

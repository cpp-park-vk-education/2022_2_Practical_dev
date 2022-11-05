#include <gtest/gtest.h>

#include <sstream>

#include "DBManager.hpp"

class DBManagerTest : public DBManager {
 public:
    void createSlavaTable() {
        // std::string str =
        //     "CREATE TABLE users( id int NOT NULL,Username char(25) NOT "
        //     "NULL,Password char(25), Email char(25));";
    }
    void InsertIntoSlava() {
        std::string str =
            "INSERT into users (id, Username, Password, Email) values "
            "('1', 'slava', 'slavapwd', 'slava@slava.ru')";
        Query(str, true);
    }
    void InsertIntoSlavaParams() {
        // std::string str =
        //     "INSERT into users (id, Username, Password, Email) values "
        //     "($1, $2, $3, $4)";
        // Query(str, true, "1", "slava", "slavapwd", "slava@slava.ru");
    }
    void SelectOutOfSlava() {
        std::string str =
            "SELECT * FROM users";
        pqxx::result response = Query(str, true);
        for (size_t i = 0; i < response.size(); i++) {
            std::cout << "id: " << response[i][0] << " Username: " << response[i][1]
                      << " Password: " << response[i][2]
                      << " Email: " << response[i][3] << std::endl;
        }
    }
};

TEST(DB, BaseTest) {
    DBManagerTest manager;
    EXPECT_NO_THROW(manager.InsertIntoSlavaParams());
    EXPECT_NO_THROW(manager.SelectOutOfSlava());
}

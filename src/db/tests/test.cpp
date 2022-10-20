#include <gtest/gtest.h>

#include <db.hpp>
#include <sstream>

TEST(DB, BaseTest) {
  std::string connectionString = "host=grechkogv.ru port=5432 dbname=slavadb "
                                 "user=slava password =slavapswd";
  try {
    std::unique_ptr<pqxx::connection> connection;
    connection.reset(new pqxx::connection(connectionString));

    pqxx::work worker(*connection);
    pqxx::result response =
        worker.exec("CREATE TABLE users( id int NOT NULL,Username char(25) NOT "
                    "NULL,Password char(25), Email char(25));"); // NOLINT
    response =
        worker.exec("INSERT into users (id, Username, Password, Email) values "
                    "('1', 'slava', 'slavapwd', 'slava@slava.ru')"); // NOLINT

    response = worker.exec("SELECT * FROM users");

    for (size_t i = 0; i < response.size(); i++) {
      std::cout << "id: " << response[i][0] << " Username: " << response[i][1]
                << " Password: " << response[i][2]
                << " Email: " << response[i][3] << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

#include <pqxx/pqxx>

#include "Comment.hpp"

class DBComment {
 private:
    pqxx::work worker;

 public:
    DBComment();

    Comment Select(const std::string& query);
    std::vector<Comment> SelectMany(const std::string& query, size_t n, size_t page = 1);

    Comment Insert(const Comment& obj);

    Comment Update(const Comment& obj);

    void Delete(const Comment& obj);
};

#pragma once

#include <pqxx/pqxx>

#include "CommentRepository.hpp"

class DBCommentImpl : DBComment {
 private:
    pqxx::work worker;

 public:
    DBCommentImpl();

    Comment Select(const std::string& query);
    Comment Insert(const Comment& obj);
    Comment Update(const Comment& obj);
    int Delete(const Comment& obj);

    Comment Sage(const Comment& obj);
    Comment Bump(const Comment& obj);
};

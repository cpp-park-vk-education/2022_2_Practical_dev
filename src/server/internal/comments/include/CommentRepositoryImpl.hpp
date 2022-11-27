#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "CommentRepository.hpp"
#include "DBManager.hpp"

class DBCommentImpl : DBComment {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    DBCommentImpl();

    Comment Select(const std::string& query);
    Comment Insert(const Comment& obj);
    Comment Update(const Comment& obj);
    int Delete(const Comment& obj);

    Comment Sage(const Comment& obj);
    Comment Bump(const Comment& obj);
};

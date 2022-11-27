#pragma once

#include <pqxx/pqxx>

#include "Comment.hpp"

class DBComment {
 private:
 public:
    DBComment();
    virtual Comment Select(const std::string& query);
    virtual Comment Insert(const Comment& obj);
    virtual Comment Update(const Comment& obj);
    virtual int Delete(const Comment& obj);
    virtual Comment Sage(const Comment& obj);
    virtual Comment Bump(const Comment& obj);
};

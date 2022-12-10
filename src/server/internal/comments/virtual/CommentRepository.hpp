#pragma once

#include <pqxx/pqxx>

#include "Comment.hpp"

class CommentRepository {
 private:
 public:
    CommentRepository() = default;

    virtual Comment Select(const std::string& query) = 0;
    virtual Comment Insert(const Comment& obj) = 0;
    virtual Comment Update(const Comment& obj) = 0;
    virtual int Delete(const Comment& obj) = 0;

    virtual Comment Sage(const Comment& obj) = 0;
    virtual Comment Bump(const Comment& obj) = 0;

    ~CommentRepository() = default;
};

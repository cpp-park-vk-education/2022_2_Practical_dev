#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "CommentRepository.hpp"
#include "DBManager.hpp"

class CommentRepositoryImpl : CommentRepository {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    CommentRepositoryImpl();

    Comment Select(const std::string& query) override;
    Comment Insert(const Comment& obj) override;
    Comment Update(const Comment& obj) override;
    int Delete(const Comment& obj) override;

    Comment Sage(const Comment& obj) override;
    Comment Bump(const Comment& obj) override;
};

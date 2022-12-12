#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "DBManager.hpp"
#include "Image.hpp"

class ImageRepositoryImpl {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    ImageRepositoryImpl();

    Image SelectById(const size_t& id);
    Image SelectByTaskId(const size_t& id);
    std::vector<Image> SelectMany(const std::string& query, size_t n, size_t page = 1);

    Image Insert(const Image& obj);

    int Update(const Image& obj);

    int Delete(const Image& obj);

    ~ImageRepositoryImpl() = default;
};

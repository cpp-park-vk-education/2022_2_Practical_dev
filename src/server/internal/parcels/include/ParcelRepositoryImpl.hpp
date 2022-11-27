#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "DBManager.hpp"
#include "ParcelRepository.hpp"

class ParcelRepositoryImpl : ParcelRepository {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    ParcelRepositoryImpl();

    Parcel Select(const std::string& query) override;
    std::vector<Parcel> SelectMany(const std::string& query, size_t n, size_t page = 1) override;

    Parcel Insert(const Parcel& obj) override;

    Parcel Update(const Parcel& obj) override;

    void Delete(const Parcel& obj) override;
};

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

    Parcel SelectById(const size_t& id) override;
    std::vector<Parcel> SelectMany(const std::string& query, size_t n, size_t page = 1) override;

    Parcel Insert(const Parcel& obj) override;

    int Update(const Parcel& obj) override;

    int Delete(const Parcel& obj) override;

    ~ParcelRepositoryImpl();
};

#pragma once

#include <functional>
#include <pqxx/pqxx>

#include "DBManager.hpp"
#include "ParcelRepository.hpp"

class DBParcelImpl : DBParcel {
 private:
    std::shared_ptr<DBManager> manager;

 public:
    DBParcelImpl();

    Parcel Select(const std::string& query);
    std::vector<Parcel> SelectMany(const std::string& query, size_t n, size_t page = 1);

    Parcel Insert(const Parcel& obj);

    Parcel Update(const Parcel& obj);

    void Delete(const Parcel& obj);
};

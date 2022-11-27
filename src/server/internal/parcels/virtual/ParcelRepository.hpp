#pragma once

#include <pqxx/pqxx>

#include "Parcel.hpp"

class ParcelRepository {
 private:
 public:
    ParcelRepository() = default;

    virtual Parcel Select(const std::string& query) = 0;
    virtual std::vector<Parcel> SelectMany(const std::string& query, size_t n, size_t page = 1) = 0;

    virtual Parcel Insert(const Parcel& obj) = 0;

    virtual Parcel Update(const Parcel& obj) = 0;

    virtual void Delete(const Parcel& obj) = 0;

    ~ParcelRepository() = default;
};

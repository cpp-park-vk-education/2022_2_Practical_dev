#pragma once

#include <pqxx/pqxx>

#include "Parcel.hpp"

class ParcelRepository {
 private:
 public:
    ParcelRepository() = default;

    virtual Parcel SelectById(const size_t& id) = 0;
    virtual std::vector<Parcel> SelectMany(const std::string& query, size_t n, size_t page = 1) = 0;

    virtual Parcel Insert(const Parcel& obj) = 0;

    virtual int Update(const Parcel& obj) = 0;

    virtual int Delete(const Parcel& obj) = 0;

    ~ParcelRepository() = default;
};

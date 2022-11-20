#include <pqxx/pqxx>

#include "Parcel.hpp"

class DBParcel {
 private:
    pqxx::work worker;

 public:
    DBParcel();

    Parcel Select(const std::string& query);
    std::vector<Parcel> SelectMany(const std::string& query, size_t n, size_t page = 1);

    Parcel Insert(const Parcel& obj);

    Parcel Update(const Parcel& obj);

    void Delete(const Parcel& obj);
};

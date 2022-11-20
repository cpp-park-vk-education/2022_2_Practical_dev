#include <pqxx/pqxx>

#include "Parcel.hpp"

class DBParcel {
 private:
    pqxx::work worker;

 public:
    DBParcel();

    virtual Parcel Select(const std::string& query);
    virtual std::vector<Parcel> SelectMany(const std::string& query, size_t n, size_t page = 1);

    virtual Parcel Insert(const Parcel& obj);

    virtual Parcel Update(const Parcel& obj);

    virtual void Delete(const Parcel& obj);
};

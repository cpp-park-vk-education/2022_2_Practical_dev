#pragma once

#include "Parcel.hpp"

class IParcelAPI {
 public:
    IParcelAPI();

    virtual Parcel getParcel(const size_t id) = 0;

    virtual Parcel addParcel(const Parcel& obj) = 0;

    virtual Parcel modifyParcel(const Parcel& obj) = 0;

    virtual void deleteParcel(const size_t id) = 0;
};

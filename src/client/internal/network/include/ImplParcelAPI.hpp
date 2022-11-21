#pragma once

#include "IParcelAPI.hpp"

class ImplParcelAPI: public IParcelAPI {
 public:
    ImplParcelAPI();

    virtual Parcel getParcel(const size_t id);

    virtual Parcel addParcel(const Parcel& obj);

    virtual Parcel modifyParcel(const Parcel& obj);

    virtual void deleteParcel(const size_t id);
};

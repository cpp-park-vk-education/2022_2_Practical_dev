#pragma once

#include "IParcelAPI.hpp"

class ImplParcelAPI: public IParcelAPI {
 public:
    ImplParcelAPI();
    ~ImplParcelAPI();

    Parcel getParcel(const size_t id) override;

    Parcel addParcel(const Parcel& obj) override;

    Parcel modifyParcel(const Parcel& obj) override;

    void deleteParcel(const size_t id) override;
};

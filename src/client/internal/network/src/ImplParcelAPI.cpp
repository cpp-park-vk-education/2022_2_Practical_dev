#include <ImplParcelAPI.hpp>

ImplParcelAPI::ImplParcelAPI() = default;

ImplParcelAPI::~ImplParcelAPI() = default;


Parcel ImplParcelAPI::getParcel(const size_t id) {
    Parcel* _parcel = new Parcel;
    return *_parcel;
}

Parcel ImplParcelAPI::addParcel(const Parcel& obj) {
    Parcel* _parcel = new Parcel;
    return *_parcel;
}

Parcel ImplParcelAPI::modifyParcel(const Parcel& obj) {
    Parcel* _parcel = new Parcel;
    return *_parcel;
}

void ImplParcelAPI::deleteParcel(const size_t id) {

}

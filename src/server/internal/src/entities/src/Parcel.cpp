#include "Parcel.hpp"

Parcel::Parcel() {
}

size_t Parcel::getId() const noexcept {
    return size_t();
}

size_t Parcel::getUserId() const noexcept {
    return size_t();
}

size_t Parcel::getTaskId() const noexcept {
    return size_t();
}

size_t Parcel::getSourceCodeId() const noexcept {
    return size_t();
}

std::string Parcel::getResult() const noexcept {
    return std::string();
}

bool Parcel::getIfBest() const noexcept {
    return false;
}

std::time_t Parcel::getRunTime() const noexcept {
    return std::time_t();
}

float Parcel::getRunMemory() const noexcept {
    return 0.0f;
}

size_t Parcel::getFailedTest() const noexcept {
    return size_t();
}

size_t Parcel::getPoints() const noexcept {
    return size_t();
}

void Parcel::setId(const size_t& id) noexcept {
}

void Parcel::setUserId(const size_t& id) noexcept {
}

void Parcel::setTaskId(const size_t& id) noexcept {
}

void Parcel::setSourceCodeId(const size_t& id) noexcept {
}

void Parcel::setResult(const std::string& result) noexcept {
}

void Parcel::setIfBest(const bool& is) const noexcept {
}

void Parcel::setRunTime(const std::time_t& usage) const noexcept {
}

void Parcel::setRunMemory(const float& usage) const noexcept {
}

void Parcel::setFailedTest(const size_t& num) noexcept {
}

void Parcel::setPoints(const size_t& points) noexcept {
}

bool Parcel::operator==(const Parcel& rhs) const noexcept {
    return false;
}

Parcel::~Parcel() {
}

std::ostream& operator<<(std::ostream& os, const Parcel& it) noexcept {
    // TODO(geogreck): insert return statement here
}

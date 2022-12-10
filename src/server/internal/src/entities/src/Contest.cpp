#include "Contest.hpp"

Contest::Contest() {
}

Contest::Contest(size_t id, const std::string& name, const std::string& description,
                 const std::string& password) {
}

size_t Contest::getId() const noexcept {
    return size_t();
}

std::string Contest::getName() const noexcept {
    return std::string();
}

std::string Contest::getDescription() const noexcept {
    return std::string();
}

std::string Contest::getPassword() const noexcept {
    return std::string();
}

std::time_t Contest::getStartTime() const noexcept {
    return std::time_t();
}

std::time_t Contest::getEndTime() const noexcept {
    return std::time_t();
}

void Contest::setId(const size_t& id) noexcept {
}

void Contest::setName(const std::string& name) noexcept {
}

void Contest::setDescription(const std::string& description) noexcept {
}

void Contest::setPassword(const std::string& password) noexcept {
}

void Contest::setStartTime(const std::time_t& time) noexcept {
}

void Contest::setEndTime(const std::time_t& time) noexcept {
}

bool Contest::operator==(const Contest& rhs) const noexcept {
    return false;
}

Contest::~Contest() noexcept {
}

std::ostream& operator<<(std::ostream& os, const Contest& it) noexcept {
    // TODO(geogreck): insert return statement here
}

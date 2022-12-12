#include "Contest.hpp"

Contest::Contest(size_t id, const std::string& name, const std::string& description,
                 const std::string& password) : id(id), name(name), description(description), password(password) {
}

size_t Contest::getId() const noexcept {
    return id;
}

std::string Contest::getName() const noexcept {
    return name;
}

std::string Contest::getDescription() const noexcept {
    return description;
}

std::string Contest::getPassword() const noexcept {
    return password;
}

std::time_t Contest::getStartTime() const noexcept {
    return start_time;
}

std::time_t Contest::getEndTime() const noexcept {
    return end_time;
}

void Contest::setId(const size_t& _id) noexcept {
    id = _id;
}

void Contest::setName(const std::string& _name) noexcept {
    name = _name;
}

void Contest::setDescription(const std::string& _description) noexcept {
    description = _description;
}

void Contest::setPassword(const std::string& _password) noexcept {
    password = _password;
}

void Contest::setStartTime(const std::time_t& _time) noexcept {
    start_time = _time;
}

void Contest::setEndTime(const std::time_t& _time) noexcept {
    end_time = _time;
}

bool Contest::operator==(const Contest& rhs) const noexcept {
    return name == rhs.name && description == rhs.description && start_time == rhs.start_time && end_time == rhs.end_time;  //NOLINT
}

std::ostream& operator<<(std::ostream& os, const Contest& it) noexcept {
    // TODO(geogreck): insert return statement here
}

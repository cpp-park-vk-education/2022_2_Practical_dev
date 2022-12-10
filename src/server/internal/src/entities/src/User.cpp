#include "User.hpp"

User::User() {
}

User::User(size_t, const std::string& nickname, const std::string& email, const std::string& password) {
}

size_t User::getId() const noexcept {
    return size_t();
}

std::string User::getNickname() const noexcept {
    return std::string();
}

std::string User::getEmail() const noexcept {
    return std::string();
}

std::string User::getPassword() const noexcept {
    return std::string();
}

void User::setId(size_t id) noexcept {
}

void User::setNickname(const std::string& nickname) noexcept {
}

void User::setEmail(const std::string& email) noexcept {
}

void User::setPassword(const std::string& old_password, const std::string& new_password) noexcept {
}

bool User::operator==(const User& rhs) const noexcept {
    return false;
}

User::~User() {
}

std::ostream& operator<<(std::ostream& os, const User& it) noexcept {
    // TODO(geogreck): insert return statement here
}

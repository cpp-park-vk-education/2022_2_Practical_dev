#include "User.hpp"

User::User(size_t id, const std::string& nickname, const std::string& email, const std::string& password) : user_id(id), nickname(nickname), email(email), password(password) {  //NOLINT
}

size_t User::getId() const noexcept {
    return user_id;
}

std::string User::getNickname() const noexcept {
    return nickname;
}

std::string User::getEmail() const noexcept {
    return email;
}

std::string User::getPassword() const noexcept {
    return password;
}

void User::setId(size_t id) noexcept {
    user_id = id;
}

void User::setNickname(const std::string& _nickname) noexcept {
    nickname = _nickname;
}

void User::setEmail(const std::string& _email) noexcept {
    email = _email;
}

void User::setPassword(const std::string& new_password) noexcept {
    password = new_password;
}

bool User::operator==(const User& rhs) const noexcept {
    return nickname == rhs.getNickname();
}

std::ostream& operator<<(std::ostream& os, const User& it) noexcept {
    // TODO(geogreck): insert return statement here
}

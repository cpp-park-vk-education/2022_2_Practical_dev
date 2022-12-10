#include <User.hpp>

User::User() = default;

size_t User::getId() {
    return id;
}

std::string User::getEmail() {
    return email;
}

std::string User::getNickname() {
    return nickname;
}

void User::setId(size_t idP) {
    id = idP;
}

void User::setEmail(std::string emailP) {
    email = std::move(emailP);
}

void User::setNickname(std::string nicknameP) {
    nickname = std::move(nicknameP);
}

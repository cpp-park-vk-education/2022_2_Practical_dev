#pragma once

#include <string>

#include "ValidationError.hpp"

class User {
 private:
    size_t user_id;
    std::string nickname;
    std::string email;
    std::string password;

 public:
    User();
    User(size_t, std::string nickname, std::string email, std::string password);

    size_t getId() const noexcept;
    std::string getNickname() const noexcept;
    std::string getEmail() const noexcept;
    std::string getPassword() const noexcept;

    void setId(size_t id) noexcept;
    void setNickname(std::string nickname) noexcept;
    void setEmail(std::string email) noexcept;
    void setPassword(std::string old_password, std::string new_password) noexcept;

    ValidationError Validate() const;

    friend std::ostream &operator<<(std::ostream &os, const User &it) noexcept;

    ~User();
};

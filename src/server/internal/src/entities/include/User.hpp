#pragma once

#include <string>

class User {
 private:
    size_t user_id;
    std::string nickname;
    std::string email;
    std::string password;

 public:
    User() = default;
    User(size_t id, const std::string& nickname, const std::string& email, const std::string& password);

    size_t getId() const noexcept;
    std::string getNickname() const noexcept;
    std::string getEmail() const noexcept;
    std::string getPassword() const noexcept;

    void setId(size_t id) noexcept;
    void setNickname(const std::string& nickname) noexcept;
    void setEmail(const std::string& email) noexcept;
    void setPassword(const std::string& new_password) noexcept;

    bool operator==(const User& rhs) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const User& it) noexcept;

    ~User() = default;
};

#pragma once

#include <iostream>
#include "Entity.hpp"


class User: public Entity {
 private:
    size_t id;
    std::string nickname;
    std::string email;

 public:
    User();

    size_t getId();
    std::string getEmail();
    std::string getNickname();

    void setId(size_t id);
    void setEmail(std::string email);
    void setNickname(std::string nickname);
};

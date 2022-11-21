#pragma once

#include <iostream>
#include "Entity.hpp"


class User: public Entity {
 private:
    size_t uuid;
    size_t owner_id;
    std::string name;
    std::string description;
    std::time_t start_time;
    std::time_t end_time;
 public:
    size_t getId();
    std::string getEmail();
    std::string getNickname();

    void setId(size_t id);
    void setEmail(std::string email);
    void setNickname(std::string nickname);




};

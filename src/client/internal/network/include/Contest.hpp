#pragma once

#include <iostream>
#include "Entity.hpp"

class Context: public Entity {
 private:
    size_t uuid;
    size_t id;
    std::string name;
    std::string description;
    std::string container;
    std::time_t start;
    std::time_t end;

 public:
    size_t getUuid();
    size_t getIdContest();
    std::string getName();
    std::string getDescription();
    std::time_t getStartTime();
    std::time_t getEndTime();

    void setUuid(size_t uuid);
    void setIdContest(size_t id);
    void setName(std::string name);
    void setDescription(std::string description);
    void setStartTime(std::time_t start);
    void setEndTime(std::time_t end);

};

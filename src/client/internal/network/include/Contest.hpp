#pragma once

#include <iostream>
#include "Entity.hpp"

class Contest: public Entity {
 private:
    size_t uuid;
    size_t id;
    std::string name;
    std::string description;
    std::string container;
    Data start;
    Data end;

 public:
    size_t getUuid();
    size_t getIdContest();
    std::string getName();
    std::string getDescription();
    Data getStartTime();
    Data getEndTime();

    void setUuid(size_t uuid);
    void setIdContest(size_t id);
    void setName(std::string name);
    void setDescription(std::string description);
    void setStartTime(Data start);
    void setEndTime(Data end);
};

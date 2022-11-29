#pragma once

#include <iostream>
#include <cstddef>
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
    Contest();
    size_t getUuid();
    size_t getIdContest();
    std::string getName();
    std::string getDescription();
    std::string getContainer();
    Data getStartTime();
    Data getEndTime();

    void setUuid(size_t uuidP);
    void setIdContest(size_t idP);
    void setName(std::string nameP);
    void setDescription(std::string descriptionP);
    void setContainer(std::string containerP);
    void setStartTime(Data startP);
    void setEndTime(Data endP);
};

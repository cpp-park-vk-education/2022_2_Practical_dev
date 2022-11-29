#pragma once

#include <iostream>
#include <cstddef>
#include "Entity.hpp"

class Task: public Entity {
 private:
    int uuid;
    int contestId;
    std::string name;
    std::string description;
    std::string container;
    int cost;
 public:
    Task();
    size_t getId();
    size_t getIdContest();
    std::string getDescription();
    std::string getName();
    std::string getContainer();
    int getCost();

    void setId(size_t id);
    void setIdContest(size_t contestId);
    void setDescription(std::string description);
    void setName(std::string name);
    void setContainer(std::string container);
    void setCost(int cost);
};

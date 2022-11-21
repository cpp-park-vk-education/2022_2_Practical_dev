#pragma once

#include <iostream>
#include "Entity.hpp"

class Task: public Entity {
 private:
    int uuid;
    int contest_id;
    std::string name;
    std::string description;
    std::string container;
    int cost;
 public:
    size_t getId();
    size_t getIdContest();
    std::string getDescription();
    std::string getName();
    std::string getContainer();
    size_t getCost();

    void setId(size_t id);
    void setIdContest(size_t contestId);
    void setDescription(std::string description);
    void setName(std::string name);
    void setContainer(std::string container);
    void setCost(size_t cost);

};

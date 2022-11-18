#pragma once

#include <iostream>

class Context {
 private:
    size_t uuid;
    size_t contest_id;
    std::string name;
    std::string description;
    std::string container;
    size_t cost;
};

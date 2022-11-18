#pragma once

#include <iostream>

struct Data {
};

class User {
 private:
    size_t uuid;
    size_t owner_id;
    std::string name;
    std::string description;
    Data start_time;
    Data end_time;
};

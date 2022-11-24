#pragma once

#include <iostream>
#include <vector>
#include <cstddef>

struct Data {
    int year;
    int mouth;
    int day;
    int hour;
    int minute;
};

struct Request {
    int codeRequest;
    std::string requestDescription;
};

class Entity {
 public:
    Entity() = default;
    Request request;
};

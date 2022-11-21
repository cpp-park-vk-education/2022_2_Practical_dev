#pragma once

#include <iostream>
#include <vector>

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
    Request request;
};


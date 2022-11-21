#pragma once

#include <iostream>

struct Request {
    int codeRequest;
    std::string requestDescription;
};

class Entity {
    Request request;
};


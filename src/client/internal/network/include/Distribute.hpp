#pragma once

#include <iostream>

#include "iContestAPI.hpp"
#include "IParcelAPI.hpp"
#include "ITaskAPI.hpp"
#include "IUserAPI.hpp"

class Distribute {
 public:
    IUserAPI* user;
    IContestAPI* contest;
    ITaskAPI* task;
    IParcelAPI* parcel;
};

#pragma once

#include <iostream>

#include "Contest.hpp"
#include "Parcel.hpp"
#include "Task.hpp"
#include "User.hpp"

class Distribute {
 public:
    *IUserAPI user;
    *IContestAPI contest;
    *ITaskAPI task;
    *IParcelAPI parcel;
};

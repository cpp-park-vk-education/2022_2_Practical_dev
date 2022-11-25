#pragma once

#include <iostream>

#include "ImplContestAPI.hpp"
#include "ImplParcelAPI.hpp"
#include "ImplTaskAPI.hpp"
#include "ImplUserAPI.hpp"

class Distribute {
 public:
    ImplUserAPI* user;
    ImplContestAPI* contest;
    ImplTaskAPI* task;
    ImplParcelAPI* parcel;
};

#pragma once

#include <vector>

#include "parcels/parcels.hpp"
#include "comments/comments.hpp"

class Task;

class TaskInterface {
    static void get(Task &task);
    static std::vector<Parcel> get_parcels(Task &task);
    static std::vector<Comment> get_comments(Task &task);
};
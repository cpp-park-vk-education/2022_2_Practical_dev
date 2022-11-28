#pragma once

#include <set>

#include "parcels/parcels.hpp"
#include "comments/comments.hpp"

class Task;

class TaskInterface {
    static Task get(Task &task);
    static std::set<Parcel> get_parcels(Task &task);
    static std::set<Comment> get_comments(Task &task);
};
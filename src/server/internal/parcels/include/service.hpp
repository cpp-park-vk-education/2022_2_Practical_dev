#pragma once

#include "tasks/tasks.hpp"

class Parcel;
class CodeSource;

class ParcelInterdace {
    static Parcel get(Parcel &parcel);
    static Parcel add(Task &task, CodeSource &src);
};
#pragma once

#include "tasks/tasks.hpp"

class Parcel;
class CodeSource;

class ParcelServiceInterdace {
 public:
    virtual Parcel get(Parcel &parcel) = 0;
    virtual Parcel add(Task &task, CodeSource &src) = 0;
};

class DBParcel;

class ParcelService : ParcelServiceInterdace {
    DBParcel &repository;
 public:
    Parcel get(Parcel &parcel);
    Parcel add(Task &task, CodeSource &src);
};
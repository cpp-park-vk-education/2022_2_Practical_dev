#pragma once

#include <iostream>
#include "Entity.hpp"

class Parcel: public Entity {
 private:
    size_t id;
    size_t userId;
    size_t taskId;
    char result;
    bool isBest;
    Data runningTime;
    float runningMemory;
    size_t failedTest;
    size_t points;

 public:
    Parcel();

    size_t getId();
    size_t getUserId();
    size_t getTaskId();
    char getResult();
    bool getIsBest();
    Data getRunningTime();
    float getRunningMemory();
    size_t getFailedTest();
    size_t getPoints();

    void setId(size_t id);
    void setUserId(size_t userId);
    void setTaskId(size_t TaskId);
    void setResult(char result);
    void setIsBest(bool isBest);
    void setRunningTime(Data runningTime);
    void setRunningMemory(float memory);
    void setFailedTest(size_t failedTest);
    void setPoints(size_t points);
};

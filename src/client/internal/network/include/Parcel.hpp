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
    std::time_t runningTime;
    float runningMemory;
    size_t failedTest;
    stze_t points;

 public:
    stze_t getId();
    size_t getUserId();
    size_t getTaskId();
    charn getResult();
    bool getIsBest();
    std::time_t getRunningTime();
    float getRunningMemory();
    size_t getFailedTest();
    size_t getPoints();

    void setId(size_t id);
    void setUserId(size_t userId);
    void setTaskId(size_t TaskId);
    void setResult(char result);
    void setIsBest(bool isBest);
    void setRunningTime(std::time_t time);
    void setRunningMemory(float memory);
    void setFailedTest(size_t failedTest);
    void setPoints(size_t points);
};

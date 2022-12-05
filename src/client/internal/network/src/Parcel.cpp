#include <Parcel.hpp>

Parcel::Parcel() = default;

size_t Parcel::getId() {
    return id;
}

size_t Parcel::getUserId() {
    return userId;
}

size_t Parcel::getTaskId() {
    return taskId;
}

std::string Parcel::getResult() {
    return result;
}

bool Parcel::getIsBest() {
    return isBest;
}

Data Parcel::getRunningTime() {
    return runningTime;
}

float Parcel::getRunningMemory() {
    return runningMemory;
}

size_t Parcel::getFailedTest() {
    return failedTest;
}

size_t Parcel::getPoints() {
    return points;
}

void Parcel::setId(size_t idP) {
    id = idP;
}

void Parcel::setUserId(size_t userIdP) {
    userId = userIdP;
}

void Parcel::setTaskId(size_t taskIdP) {
    taskId = taskIdP;
}

void Parcel::setResult(std::string resultP) {
    result = std::move(resultP);
}

void Parcel::setIsBest(bool isBestP) {
    isBest = isBestP;
}

void Parcel::setRunningTime(Data runningTimeP) {
    runningTime = runningTimeP;
}

void Parcel::setRunningMemory(float memoryP) {
    runningMemory = memoryP;
}

void Parcel::setFailedTest(size_t failedTestP) {
    failedTest = failedTestP;
}

void Parcel::setPoints(size_t pointsP) {
    points = pointsP;
}

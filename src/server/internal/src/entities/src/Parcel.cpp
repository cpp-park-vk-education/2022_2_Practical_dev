#include "Parcel.hpp"

Parcel::Parcel(const size_t& user_id, const size_t& task_id, const size_t& source_id, const std::string& result) : fk_user_id(user_id), fk_tasks_id(task_id), fk_source_code_id(source_id) {
}

size_t Parcel::getId() const noexcept {
    return id;
}

size_t Parcel::getUserId() const noexcept {
    return fk_user_id;
}

size_t Parcel::getTaskId() const noexcept {
    return fk_tasks_id;
}

size_t Parcel::getSourceCodeId() const noexcept {
    return fk_source_code_id;
}

std::string Parcel::getResult() const noexcept {
    return result;
}

bool Parcel::getIfBest() const noexcept {
    return is_best;
}

std::time_t Parcel::getRunTime() const noexcept {
    return run_time;
}

float Parcel::getRunMemory() const noexcept {
    return run_memory;
}

size_t Parcel::getFailedTest() const noexcept {
    return failed_test;
}

size_t Parcel::getPoints() const noexcept {
    return points;
}

void Parcel::setId(const size_t& _id) noexcept {
    id = _id;
}

void Parcel::setUserId(const size_t& id) noexcept {
    fk_user_id = id;
}

void Parcel::setTaskId(const size_t& id) noexcept {
    fk_tasks_id = id;
}

void Parcel::setSourceCodeId(const size_t& id) noexcept {
    fk_source_code_id = id;
}

void Parcel::setResult(const std::string& _result) noexcept {
    result = _result;
}

void Parcel::setIfBest(const bool& is) noexcept {
    is_best = is;
}

void Parcel::setRunTime(const std::time_t& usage) noexcept {
    run_time = usage;
}

void Parcel::setRunMemory(const float& usage) noexcept {
    run_memory = usage;
}

void Parcel::setFailedTest(const size_t& num) noexcept {
    failed_test = num;
}

void Parcel::setPoints(const size_t& _points) noexcept {
    points = _points;
}

bool Parcel::operator==(const Parcel& rhs) const noexcept {
    return rhs.fk_source_code_id == fk_source_code_id;
}

std::ostream& operator<<(std::ostream& os, const Parcel& it) noexcept {
    // TODO(geogreck): insert return statement here
    return os;
}

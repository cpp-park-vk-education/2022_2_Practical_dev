#include "Task.hpp"

Task::Task() {
}

Task::Task(size_t contest_id, const std::string& name, const std::string& desc, size_t cost, float memory_limit) {
}

size_t Task::getId() const noexcept {
    return size_t();
}

size_t Task::getContestId() const noexcept {
    return size_t();
}

std::string Task::getName() const noexcept {
    return std::string();
}

std::string Task::getDescription() const noexcept {
    return std::string();
}

size_t Task::getCost() const noexcept {
    return size_t();
}

float Task::getMemoryLimit() const noexcept {
    return 0.0f;
}

std::time_t Task::getTimeLimit() const noexcept {
    return std::time_t();
}

void Task::setId(const size_t& id) noexcept {
}

void Task::setContestId(const size_t& id) noexcept {
}

void Task::setName(const std::string& name) noexcept {
}

void Task::setDescription(const std::string& desc) noexcept {
}

void Task::setCost(const size_t& cost) noexcept {
}

void Task::setMemoryLimit(const float& lim) noexcept {
}

void Task::setTimeLimit(const std::time_t& lim) noexcept {
}

bool Task::operator==(const Task& rhs) const noexcept {
    return false;
}

Task::~Task() {
}

std::ostream& operator<<(std::ostream& os, const Task& it) noexcept {
    // TODO(geogreck): insert return statement here
}

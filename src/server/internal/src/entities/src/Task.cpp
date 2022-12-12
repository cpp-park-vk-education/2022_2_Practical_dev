#include "Task.hpp"

Task::Task(size_t contest_id, const std::string& name, const std::string& desc, size_t cost, float memory_limit) : fk_contest_id(contest_id), name(name), description(desc), cost(cost), memory_limit(memory_limit) {  //NOLINT
}

size_t Task::getId() const noexcept {
    return id;
}

size_t Task::getContestId() const noexcept {
    return fk_contest_id;
}

std::string Task::getName() const noexcept {
    return name;
}

std::string Task::getDescription() const noexcept {
    return description;
}

size_t Task::getCost() const noexcept {
    return cost;
}

float Task::getMemoryLimit() const noexcept {
    return memory_limit;
}

std::time_t Task::getTimeLimit() const noexcept {
    return time_limit;
}

void Task::setId(const size_t& _id) noexcept {
    id = _id;
}

void Task::setContestId(const size_t& id) noexcept {
    fk_contest_id = id;
}

void Task::setName(const std::string& _name) noexcept {
    name = _name;
}

void Task::setDescription(const std::string& desc) noexcept {
    description = desc;
}

void Task::setCost(const size_t& _cost) noexcept {
    cost = _cost;
}

void Task::setMemoryLimit(const float& lim) noexcept {
    memory_limit = lim;
}

void Task::setTimeLimit(const std::time_t& lim) noexcept {
    time_limit = lim;
}

bool Task::operator==(const Task& rhs) const noexcept {
    return rhs.name == name;
}

std::ostream& operator<<(std::ostream& os, const Task& it) noexcept {
    // TODO(geogreck): insert return statement here
}

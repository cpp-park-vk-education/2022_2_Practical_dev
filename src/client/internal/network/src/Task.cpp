#include <Task.hpp>

Task::Task() = default;

size_t Task::getId() {
    return uuid;
}

size_t Task::getIdContest() {
    return contestId;
}

std::string Task::getDescription() {
    return description;
}

std::string Task::getName() {
    return name;
}

std::string Task::getContainer() {
    return container;
}

int Task::getCost() {
    return cost;
}

void Task::setId(size_t uuidP) {
    uuid = uuidP;
}

void Task::setIdContest(size_t contestIdP) {
    contestId = contestIdP;
}

void Task::setDescription(std::string descriptionP) {
    description = std::move(descriptionP);
}

void Task::setName(std::string nameP) {
    name = std::move(nameP);
}

void Task::setContainer(std::string containerP) {
    container = std::move(containerP);
}

void Task::setCost(int costP) {
    cost = costP;
}

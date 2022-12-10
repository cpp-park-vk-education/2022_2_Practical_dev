#include <Contest.hpp>

Contest::Contest() = default;

size_t Contest::getUuid() {
    return uuid;
}

size_t Contest::getIdContest() {
    return id;
}

std::string Contest::getName() {
    return name;
}

std::string Contest::getDescription() {
    return description;
}

std::string Contest::getContainer() {
    return container;
}

Data Contest::getStartTime() {
    return start;
}

Data Contest::getEndTime() {
    return end;
}

void Contest::setUuid(size_t uuidP) {
    uuid = uuidP;
}

void Contest::setIdContest(size_t idP) {
    id = idP;
}

void Contest::setName(std::string nameP) {
    name = std::move(nameP);
}

void Contest::setDescription(std::string descriptionP) {
    description = std::move(descriptionP);
}

void Contest::setContainer(std::string containerP) {
    container = std::move(containerP);
}

void Contest::setStartTime(Data startP) {
    start = startP;
}

void Contest::setEndTime(Data endP) {
    end = endP;
}

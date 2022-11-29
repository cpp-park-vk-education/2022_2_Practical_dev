#include "Container.hpp"

Container::Container() {
}

size_t Container::getId() const noexcept {
    return size_t();
}

size_t Container::getTaskId() const noexcept {
    return size_t();
}

std::string Container::getDockerId() const noexcept {
    return std::string();
}

void Container::setId(const size_t& id) noexcept {
}

void Container::setTaskId(const size_t& id) noexcept {
}

void Container::setDockerId(const std::string& docker_id) noexcept {
}

bool Container::operator==(const Container& rhs) const noexcept {
    return false;
}

Container::~Container() {
}

std::ostream& operator<<(std::ostream& os, const Container& it) noexcept {
    // TODO(geogreck): insert return statement here
}

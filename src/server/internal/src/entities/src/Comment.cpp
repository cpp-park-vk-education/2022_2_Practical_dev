#include "Comment.hpp"

Comment::Comment() {
}

Comment::Comment(size_t parcel_id, size_t task_id, const std::string& text) {
}

size_t Comment::getId() const noexcept {
    return size_t();
}

size_t Comment::getParcelId() const noexcept {
    return size_t();
}

size_t Comment::getTaskId() const noexcept {
    return size_t();
}

std::string Comment::getText() const noexcept {
    return std::string();
}

float Comment::getRaiting() const noexcept {
    return 0.0f;
}

std::time_t Comment::getCreatedOn() const noexcept {
    return std::time_t();
}

void Comment::setId(const size_t& id) noexcept {
}

void Comment::setParcelId(const size_t& id) noexcept {
}

void Comment::setTaskId(const size_t& id) noexcept {
}

void Comment::setText(const std::string& text) noexcept {
}

void Comment::setRaiting(const float& rate) noexcept {
}

void Comment::setCreationDate(const std::time_t) noexcept {
}

bool Comment::operator==(const Comment& rhs) const noexcept {
    return false;
}

Comment::~Comment() {
}

std::ostream& operator<<(std::ostream& os, const Comment& it) noexcept {
    // TODO(geogreck): insert return statement here
}

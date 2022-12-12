#include "Comment.hpp"

Comment::Comment(size_t parcel_id, size_t task_id, const std::string& text) : fk_parcel_id(parcel_id), fk_task_id(task_id), text(text) {  //NOLINT
}

size_t Comment::getId() const noexcept {
    return id;
}

size_t Comment::getParcelId() const noexcept {
    return fk_parcel_id;
}

size_t Comment::getTaskId() const noexcept {
    return fk_task_id;
}

std::string Comment::getText() const noexcept {
    return text;
}

float Comment::getRaiting() const noexcept {
    return raiting;
}

std::time_t Comment::getCreatedOn() const noexcept {
    return created_on;
}

void Comment::setId(const size_t& _id) noexcept {
    id = _id;
}

void Comment::setParcelId(const size_t& _id) noexcept {
    fk_parcel_id = _id;
}

void Comment::setTaskId(const size_t& _id) noexcept {
    fk_task_id = _id;
}

void Comment::setText(const std::string& _text) noexcept {
    text = _text;
}

void Comment::setRaiting(const float& _rate) noexcept {
    raiting = _rate;
}

void Comment::setCreationDate(const std::time_t _time) noexcept {
    created_on = _time;
}

bool Comment::operator==(const Comment& rhs) const noexcept {
    return false;
}

std::ostream& operator<<(std::ostream& os, const Comment& it) noexcept {
    // TODO(geogreck): insert return statement here
    return os;
}

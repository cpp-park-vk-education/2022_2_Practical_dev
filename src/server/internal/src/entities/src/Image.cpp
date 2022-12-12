#include "Image.hpp"

Image::Image(const size_t& fk_task_id, const std::string& docker_id) : fk_task_id(fk_task_id), docker_id(docker_id) {
}

size_t Image::getId() const noexcept {
    return id;
}

size_t Image::getTaskId() const noexcept {
    return fk_task_id;
}

std::string Image::getDockerId() const noexcept {
    return docker_id;
}

void Image::setId(const size_t& _id) noexcept {
    id = _id;
}

void Image::setTaskId(const size_t& id) noexcept {
    fk_task_id = id;
}

void Image::setDockerId(const std::string& _docker_id) noexcept {
    docker_id = _docker_id;
}

bool Image::operator==(const Image& rhs) const noexcept {
    return fk_task_id == rhs.fk_task_id && docker_id == rhs.docker_id;
}

std::ostream& operator<<(std::ostream& os, const Image& it) noexcept {
    // TODO(geogreck): insert return statement here
}

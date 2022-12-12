#pragma once

#include <string>

class Image {
 private:
    size_t id;
    size_t fk_task_id;
    std::string docker_id;

 public:
    Image() = default;
    Image(const size_t& fk_task_id, const std::string& docker_id);

    size_t getId() const noexcept;
    size_t getTaskId() const noexcept;
    std::string getDockerId() const noexcept;

    void setId(const size_t& id) noexcept;
    void setTaskId(const size_t& id) noexcept;
    void setDockerId(const std::string& docker_id) noexcept;

    bool operator==(const Image& rhs) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Image& it) noexcept;

    ~Image() = default;
};

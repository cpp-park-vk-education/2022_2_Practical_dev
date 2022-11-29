#pragma once

#include <string>

#include "ValidationError.hpp"

class Container {
 private:
    size_t id;
    size_t fk_task_id;
    std::string docker_id;

 public:
    Container();

    size_t getId() const noexcept;
    size_t getTaskId() const noexcept;
    std::string getDockerId() const noexcept;

    void setId(const size_t& id) noexcept;
    void setTaskId(const size_t& id) noexcept;
    void setDockerId(const std::string& docker_id) noexcept;

    bool operator==(const Container& rhs) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Container& it) noexcept;

    ~Container();
};

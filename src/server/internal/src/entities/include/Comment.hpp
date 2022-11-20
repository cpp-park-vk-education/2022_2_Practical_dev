#pragma once

#include <ctime>
#include <string>

#include "ValidationError.hpp"

class Comment {
 private:
    size_t id;
    size_t fk_parcel_id;
    size_t fk_task_id;
    std::string text;
    float raiting;
    std::time_t created_on;

 public:
    Comment();

    size_t getId() const noexcept;
    size_t getParcelId() const noexcept;
    size_t getTaskId() const noexcept;
    std::string getText() const noexcept;
    float getRaiting() const noexcept;
    std::time_t getCreatedOn() const noexcept;

    void setId(const size_t& id) noexcept;
    void setParcelId(const size_t& id) noexcept;
    void setTaskId(const size_t& id) noexcept;
    void setText(const std::string& text) noexcept;
    void setRaiting(const float& rate) noexcept;
    void setCreationDate(const std::time_t) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Comment& it) noexcept;

    ~Comment();
};

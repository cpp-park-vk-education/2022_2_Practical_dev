#pragma once

#include <ctime>
#include <string>

 
#include "ValidationError.hpp"

class Contest {
 private:
    size_t id;
    std::string name;
    std::string description;
    std::string password;
    std::time_t start_time;
    std::time_t end_time;

 public:
    Contest();

    size_t getId() const noexcept;
    std::string getName() const noexcept;
    std::string getDescription() const noexcept;
    std::string getPassword() const noexcept;
    std::time_t getStartTime() const noexcept;
    std::time_t getEndTime() const noexcept;

    void setId(const size_t& id) noexcept;
    void setName(const std::string& name) noexcept;
    void setDescription(const std::string& description) noexcept;
    void setPassword(const std::string& password) noexcept;
    void setStartTime(const std::time_t& time) noexcept;
    void setEndTime(const std::time_t& time) noexcept;

    ValidationError Validate() const;

    friend std::ostream& operator<<(std::ostream& os, const Contest& it) noexcept;

    ~Contest();
};

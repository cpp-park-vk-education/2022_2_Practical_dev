#pragma once

#include <ctime>
#include <string>

class Contest {
 private:
    size_t id;
    std::string name;
    std::string description;
    std::string password;
    std::time_t start_time;
    std::time_t end_time;

 public:
    Contest() = default;
    Contest(size_t id, const std::string& name, const std::string& description, const std::string& password);

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

    bool operator==(const Contest& rhs) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Contest& it) noexcept;

    ~Contest() = default;
};

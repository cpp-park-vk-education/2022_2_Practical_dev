#pragma once

#include <ctime>
#include <string>

class Task {
 private:
    size_t id;
    size_t fk_contest_id;
    std::string name;
    std::string description;
    size_t cost;
    float memory_limit;
    std::time_t time_limit;

 public:
    Task() = default;
    Task(size_t contest_id, const std::string& name, const std::string& desc, size_t cost, float memory_limit);

    size_t getId() const noexcept;
    size_t getContestId() const noexcept;
    std::string getName() const noexcept;
    std::string getDescription() const noexcept;
    size_t getCost() const noexcept;
    float getMemoryLimit() const noexcept;
    std::time_t getTimeLimit() const noexcept;

    void setId(const size_t& id) noexcept;
    void setContestId(const size_t& id) noexcept;
    void setName(const std::string& name) noexcept;
    void setDescription(const std::string& desc) noexcept;
    void setCost(const size_t& cost) noexcept;
    void setMemoryLimit(const float& lim) noexcept;
    void setTimeLimit(const std::time_t& lim) noexcept;

    bool operator==(const Task& rhs) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const Task& it) noexcept;

    ~Task() = default;
};

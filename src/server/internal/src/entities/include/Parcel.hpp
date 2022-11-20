#pragma once

#include <ctime>
#include <string>

#include "ValidationError.hpp"

class Parcel {
 private:
    size_t id;
    size_t fk_user_id;
    size_t fk_tasks_id;
    size_t fk_source_code_id;

    std::string result;
    bool is_best;

    std::time_t run_time;
    float run_memory;
    size_t failed_test;
    size_t points;

 public:
    Parcel();

    size_t getId() const noexcept;
    size_t getUserId() const noexcept;
    size_t getTaskId() const noexcept;
    size_t getSourceCodeId() const noexcept;
    std::string getResult() const noexcept;
    bool getIfBest() const noexcept;
    std::time_t getRunTime() const noexcept;
    float getRunMemory() const noexcept;
    size_t getFailedTest() const noexcept;
    size_t getPoints() const noexcept;

    void setId(const size_t& id) noexcept;
    void setUserId(const size_t& id) noexcept;
    void setTaskId(const size_t& id) noexcept;
    void setSourceCodeId(const size_t& id) noexcept;
    void setResult(const std::string& result) noexcept;
    void setIfBest(const bool& is) const noexcept;
    void setRunTime(const std::time_t& usage) const noexcept;
    void setRunMemory(const float& usage) const noexcept;
    void setFailedTest(const size_t& num) noexcept;
    void setPoints(const size_t& points) noexcept;

    ValidationError Validate() const;

    friend std::ostream& operator<<(std::ostream& os, const Parcel& it) noexcept;

    ~Parcel();
};

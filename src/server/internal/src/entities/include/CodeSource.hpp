#pragma once

#include <string>

class CodeSource {
 private:
    size_t id;
    size_t fk_run_config_id;

    std::string source;

 public:
    CodeSource();

    size_t getId() const noexcept;
    size_t getRunConfig() const noexcept;
    std::string getSource() const noexcept;

    void setId(const size_t& id) noexcept;
    void setRunConfig(const size_t id) noexcept;
    void setSource(const std::string& code) noexcept;

    ~CodeSource() = default;
};

#include "CodeSource.hpp"

size_t CodeSource::getId() const noexcept {
    return id;
}

size_t CodeSource::getRunConfig() const noexcept {
    return fk_run_config_id;
}

std::string CodeSource::getSource() const noexcept {
    return source;
}

void CodeSource::setId(const size_t& _id) noexcept {
    id = _id;
}

void CodeSource::setRunConfig(const size_t _id) noexcept {
    fk_run_config_id = _id;
}

void CodeSource::setSource(const std::string& _code) noexcept {
    source = _code;
}

bool CodeSource::operator==(const CodeSource& rhs) const noexcept {
    return source == rhs.source && fk_run_config_id == rhs.fk_run_config_id;
}

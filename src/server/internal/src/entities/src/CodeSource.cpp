#include "CodeSource.hpp"

CodeSource::CodeSource() {
}

size_t CodeSource::getId() const noexcept {
    return size_t();
}

size_t CodeSource::getRunConfig() const noexcept {
    return size_t();
}

std::string CodeSource::getSource() const noexcept {
    return std::string();
}

void CodeSource::setId(const size_t& id) noexcept {
}

void CodeSource::setRunConfig(const size_t id) noexcept {
}

void CodeSource::setSource(const std::string& code) noexcept {
}

bool CodeSource::operator==(const CodeSource& rhs) const noexcept {
    return false;
}

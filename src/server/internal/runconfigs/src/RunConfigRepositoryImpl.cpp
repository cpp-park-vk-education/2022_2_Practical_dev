#include "RunConfigRepositoryImpl.hpp"

RunConfigRepositoryImpl::RunConfigRepositoryImpl() {
}

RunConfig RunConfigRepositoryImpl::Select(const std::string& query) {
}

RunConfig RunConfigRepositoryImpl::Select(const size_t& id) {
    return RunConfig();
}

std::vector<RunConfig> RunConfigRepositoryImpl::SelectMany(const std::string& query, size_t n, size_t page) {
}

RunConfig RunConfigRepositoryImpl::Insert(const RunConfig& obj) {
}

RunConfig RunConfigRepositoryImpl::Update(const RunConfig& obj) {
}

void RunConfigRepositoryImpl::Delete(const RunConfig& obj) {
}

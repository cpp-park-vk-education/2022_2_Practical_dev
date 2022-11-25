#include <ImplTaskAPI.hpp>

ImplTaskAPI::ImplTaskAPI() = default;

ImplTaskAPI::~ImplTaskAPI() = default;

Task ImplTaskAPI::getTask(const size_t idTask) {
    Task* task = new Task;
    return *task;
}
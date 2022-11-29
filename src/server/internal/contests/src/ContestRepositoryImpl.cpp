#include "ContestRepositoryImpl.hpp"

ContestRepositoryImpl::ContestRepositoryImpl() {
}

Contest ContestRepositoryImpl::Select(const Contest& contest) {
}

Contest ContestRepositoryImpl::Add(const Contest& obj) {
}

int ContestRepositoryImpl::DeleteUserFromContest(const Contest& obj, const User& user) {
}

int ContestRepositoryImpl::AddUserIntoContest(const Contest& obj, const User& user) {
}

int ContestRepositoryImpl::GetUsersByContest(const Contest& obj, const User& user) {
}

int ContestRepositoryImpl::DeleteTaskFromContest(const Contest& obj, const Task& user) {
}

int ContestRepositoryImpl::AddTaskIntoContest(const Contest& obj, const Task& user) {
}

std::vector<Task> ContestRepositoryImpl::GetTasksByContest(const Contest& obj) {
}

int ContestRepositoryImpl::Delete(const Contest& obj) {
}

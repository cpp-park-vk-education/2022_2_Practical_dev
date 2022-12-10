#include "UserRepositoryImpl.hpp"

UserRepositoryImpl::UserRepositoryImpl() {
}

User UserRepositoryImpl::Get(const User& user) {
}

User UserRepositoryImpl::GetById(const std::size_t& id) {
}

std::vector<User> UserRepositoryImpl::GetByContest(const size_t& id) {
}

std::vector<User> UserRepositoryImpl::GetByTask(const size_t& id) {
}

User UserRepositoryImpl::Update(const User& obj) {
}

int UserRepositoryImpl::Signin(const User& user) {
}

int UserRepositoryImpl::Signup(const User& user) {
}

int UserRepositoryImpl::DeleteContest(const User& user, const Contest& contest) {
}

int UserRepositoryImpl::AddContest(const User& user, const Contest& contest) {
}

std::vector<Contest> UserRepositoryImpl::GetContestsByUser(const User& user) {
}

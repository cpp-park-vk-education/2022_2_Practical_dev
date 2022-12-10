#include <ImplUserAPI.hpp>

ImplUserAPI::ImplUserAPI() = default;

ImplUserAPI::~ImplUserAPI() = default;

User ImplUserAPI::getUser(const size_t idUser) {
    User* user;
    return *user;
}

std::vector<Contest> ImplUserAPI::getContest(const size_t idUser) {
    std::vector<Contest> contests;
    return contests;
}

User ImplUserAPI::createUser(const User& user) {
    User* _user;
    return *_user;
}

User ImplUserAPI::modifyUser(const size_t idUser) {
    User* user;
    return *user;
}

Contest ImplUserAPI::addContestToUser(const size_t idUser, const size_t idContest) {
    Contest* contest;
    return *contest;
}

void ImplUserAPI::deleteUser(const size_t idUser) {
}

void ImplUserAPI::deleteContest(const size_t idUser, const size_t idContest) {
}

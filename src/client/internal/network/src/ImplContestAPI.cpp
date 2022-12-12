#include <ImplContestAPI.hpp>

ImplContestAPI::ImplContestAPI() = default;

ImplContestAPI::~ImplContestAPI() = default;

Contest ImplContestAPI::getContest(const size_t idContest) {
    Contest* contest;
    return *contest;
}

std::vector<Task> ImplContestAPI::getTask(const size_t idContest) {
    std::vector<Task> tasks;
    return tasks;
}

std::vector<User> ImplContestAPI::getUser(const size_t idContest) {
    std::vector<User> users;
    return users;
}

Contest ImplContestAPI::createContest(const Contest& contest) {
    Contest* _contest;
    return *_contest;
}

User ImplContestAPI::addUser(const size_t idContest, const size_t idUser) {
    User* user;
    return *user;
}

Task ImplContestAPI::addTask(const size_t idContest, const size_t idTask) {
    Task* task;
    return *task;
}

void ImplContestAPI::deleteContest(const size_t idContest) {
}

void ImplContestAPI::deleteUser(const size_t idUser, const size_t idContest) {
}

void ImplContestAPI::deleteTask(const size_t idTask, const size_t idContest) {
}

#pragma once

#include <vector>

#include "IUserAPI.hpp"

class ImplUserAPI : public IUserAPI {
 public:
    ImplUserAPI();
    ~ImplUserAPI();

    User getUser(const size_t idUser) override;
    std::vector<Contest> getContest(const size_t idUser) override;

    User createUser(const User& user) override;
    User modifyUser(const size_t idUser) override;

    Contest addContestToUser(const size_t idUser, const size_t idContest) override;

    void deleteUser(const size_t idUser) override;
    void deleteContest(const size_t idUser, const size_t idContest) override;
};

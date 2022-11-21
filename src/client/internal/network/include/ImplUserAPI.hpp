#pragma once

#include "IUserAPI.hpp"

class ImplUserAPI: public IUserAPI {
 public:
    ImplUserAPI();

    virtual User getUser(const size_t idUser);
    virtual std::vector<Contest> getContest(const size_t idUser);

    virtual User createUser(const User& user);
    virtual User modifyUser(const size_t idUser);

    virtual Contest addContestToUser(const size_t idUser, const size_t idContest);

    virtual void deleteUser(const size_t idUser);
    virtual void deleteContest(const size_t idUser, const size_t idContest);
};

#pragma once

#include <iostream>
#include "User.hpp"
#include "Contest.hpp"

class IUserAPI {
 public:
    IUserAPI();

    virtual User getUser(const size_t idUser) = 0;
    virtual std::vector<Contest> getContest(const size_t idUser) = 0;

    virtual User createUser(const User& user) = 0;
    virtual User modifyUser(const size_t idUser) = 0;

    virtual Contest addContestToUser(const size_t idUser, const size_t idContest) = 0;

    virtual void deleteUser(const size_t idUser) = 0;
    virtual void deleteContest(const size_t idUser, const size_t idContest) = 0;
};

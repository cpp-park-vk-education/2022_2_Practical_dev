#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

#include "User.hpp"
#include "Task.hpp"
#include "Contest.hpp"
#include "Parcel.hpp"


class requestDistributors {
 public:
    requestDistributors() = default;
    ~requestDistributors() = default;

//  USER
    // "Get"
    User getUser(size_t idUser);
    std::vector<Contest> getUserContents(size_t idContest);
    // "Put"
    User modifyUser(size_t idUser);
    addContestToUser(size_t idUser, size_t idContest);
    // "Post"
    User createUser(std::string nickname, std::string email, std::string password);
    // "Delete"
    deleteUser(size_t idUser);
    deleteContestFromUser(size_t idUser, size_t idContest);

//  CONTEXT
    // "Get"
    Contest getContest(size_t idContest);
    std::vector<Task> getTasksContest(size_t idContest);
    std::vector<User> getParticipantsContest(size_t idContest);
    // "Put"
    User createContest(std::string name, std::string description, Data start, Data end);
    addUserToContest(size_t idContest, size_t idUser);
    Task addTaskToContest(size_t idContest, size_t idTask);
    // "Delete"
    deleteContest(size_t idContest);
    deleteTaskFromContest(size_t idTask, size_t idContest);
    deleteUserFromContest(size_t idUser, size_t idContest);

//  TASK
    Task getTask(size_t idTask);
};

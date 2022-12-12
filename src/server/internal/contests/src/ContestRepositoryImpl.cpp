#include "ContestRepositoryImpl.hpp"

#include <iostream>

ContestRepositoryImpl::ContestRepositoryImpl() {
}

Contest ContestRepositoryImpl::Select(const Contest& contest) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "SELECT contest_id, name, password, description, start_time, end_time FROM Contests\n"
        "WHERE contest_id = $1;",
        contest.getId());

    Contest new_obj;
    new_obj.setId(std::atoi(res[0].c_str()));
    new_obj.setName(res[1].c_str());
    new_obj.setPassword(res[2].c_str());
    new_obj.setDescription(res[3].c_str());
    new_obj.setStartTime(std::atoi(res[4].c_str()));
    new_obj.setEndTime(std::atoi(res[5].c_str()));

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));
    return new_obj;
}

std::vector<Contest> ContestRepositoryImpl::SelectAll() {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::result res = worker->exec(
        "SELECT contest_id, name, password, description, start_time, end_time FROM Contests;\n");

    std::vector<Contest> contests;

    for (size_t i = 0; i < res.size(); i++) {
        Contest new_obj;
        new_obj.setId(std::atoi(res[i][0].c_str()));
        new_obj.setName(res[i][1].c_str());
        new_obj.setPassword(res[i][2].c_str());
        new_obj.setDescription(res[i][3].c_str());
        new_obj.setStartTime(std::atoi(res[i][4].c_str()));
        new_obj.setEndTime(std::atoi(res[i][5].c_str()));
        contests.push_back(new_obj);
    }

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));
    return contests;
}

Contest ContestRepositoryImpl::Add(const Contest& obj) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "INSERT INTO Contests"
        "(name, password, description, start_time, end_time)"
        "VALUES($1, $2, $3, $4, $5)"
        "RETURNING contest_id;",
        obj.getName(), obj.getPassword(), obj.getDescription(), obj.getStartTime(), obj.getEndTime());

    size_t id = std::atoi(res[0].c_str());
    Contest new_obj = obj;
    new_obj.setId(id);

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return new_obj;
}

int ContestRepositoryImpl::DeleteUserFromContest(const Contest& obj, const User& user) {
    if (obj.getId() == 0 || user.getId() == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "DELETE FROM Users_Contests \n"
        "WHERE fk_user_id = $1 AND fk_contest_id = $2;",
        user.getId(), obj.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

int ContestRepositoryImpl::AddUserIntoContest(const Contest& obj, const User& user) {
    if (obj.getId() == 0 || user.getId() == 0) {
        return 404;
    }
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "INSERT INTO Contests"
        "(fk_contest_id, fk_user_id, is_admin)"
        "VALUES($1, $2, $3);",
        obj.getId(), user.getId(), false);

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

std::vector<User> ContestRepositoryImpl::GetUsersByContest(const Contest& obj) {
    if (obj.getId() == 0) {
        return std::vector<User>();
    }

    return std::vector<User>();
}

int ContestRepositoryImpl::DeleteTaskFromContest(const Contest& obj, const Task& task) {
    if (obj.getId() == 0 || task.getId()) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "DELETE FROM Tasks \n"
        "WHERE task_id = $1;",
        task.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

int ContestRepositoryImpl::AddTaskIntoContest(const Contest& obj, const Task& task) {
    if (obj.getId() == 0) {
        return 404;
    }
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params1(
        "INSERT INTO Tasks"
        "(fk_contest_id,name,description,cost,memory_limit,time_limit)\n"
        "VALUES ($1, $2, $3, $4, $5, $6)"
        "RETURNING task_id;",
        obj.getId(), task.getName(), task.getDescription(), task.getCost(), task.getMemoryLimit(), task.getTimeLimit());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

std::vector<Task> ContestRepositoryImpl::GetTasksByContest(const Contest& obj) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::result res = worker->exec_params(
        "SELECT task_id, fk_contest_id, name, description, cost, memory_limit, time_limit FROM Tasks\n"
        "WHERE fk_contest_id = $1;",
        obj.getId());

    std::vector<Task> tasks;

    for (size_t i = 0; i < res.size(); i++) {
        Task new_obj;
        new_obj.setId(std::atoi(res[i][0].c_str()));
        new_obj.setName(res[i][1].c_str());
        new_obj.setDescription(res[i][3].c_str());
        new_obj.setCost(std::atoi(res[i][4].c_str()));
        new_obj.setMemoryLimit(std::atof(res[i][4].c_str()));
        new_obj.setTimeLimit(std::atoi(res[i][5].c_str()));
        tasks.push_back(new_obj);
    }

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));
    return tasks;
}

int ContestRepositoryImpl::Delete(const Contest& obj) {
    if (obj.getId() == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "DELETE FROM Tasks \n"
        "WHERE fk_contest_id = $1;",
        obj.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "DELETE FROM Contests \n"
        "WHERE contest_id = $1;",
        obj.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));
    return 0;
}

#include "RunConfigRepositoryImpl.hpp"

#include <iostream>

RunConfigRepositoryImpl::RunConfigRepositoryImpl() {
}

RunConfig RunConfigRepositoryImpl::SelectById(const size_t& id) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "SELECT run_config_id, compiler,interpreter,name,compiler_flags,interpreter_flags FROM RunConfigs\n"
        "WHERE run_config_id = $1",
        id);

    RunConfig new_obj;
    new_obj.id = std::atoi(res[0].c_str());
    new_obj.compiler = res[2].c_str();
    new_obj.interpreter = res[2].c_str();
    new_obj.name = res[3].c_str();
    new_obj.compiler_flags = res[4].c_str();
    new_obj.interpreter_flags = res[5].c_str();

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));
    return new_obj;
}

RunConfig RunConfigRepositoryImpl::SelectByName(const std::string& name) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::result res = worker->exec_params(
        "SELECT run_config_id, compiler,interpreter,name,compiler_flags,interpreter_flags FROM RunConfigs\n"
        "WHERE name = $1",
        name);

    RunConfig new_obj;
    new_obj.id = std::atoi(res[0][0].c_str());
    new_obj.compiler = res[0][1].c_str();
    new_obj.interpreter = res[0][2].c_str();
    new_obj.name = res[0][3].c_str();
    new_obj.compiler_flags = res[0][4].c_str();
    new_obj.interpreter_flags = res[0][5].c_str();

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return new_obj;
}

RunConfig RunConfigRepositoryImpl::Insert(const RunConfig& obj) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "INSERT INTO RunConfigs"
        "(compiler,interpreter,name,compiler_flags,interpreter_flags)"
        "VALUES($1, $2, $3, $4, $5)"
        "RETURNING run_config_id;",
        obj.compiler, obj.interpreter, obj.name, obj.compiler_flags, obj.interpreter_flags);

    size_t id = std::atoi(res[0].c_str());
    RunConfig new_obj = obj;
    new_obj.id = id;

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return new_obj;
}

int RunConfigRepositoryImpl::Update(const RunConfig& obj) {
    if (obj.id == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "UPDATE RunConfigs SET\n"
        "compiler = $1, interpreter = $2, name = $3, compiler_flags = $4, interpreter_flags = $5\n"
        "WHERE run_config_id = $6;",
        obj.compiler, obj.interpreter, obj.name, obj.compiler_flags, obj.interpreter_flags, obj.id);

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

int RunConfigRepositoryImpl::Delete(const RunConfig& obj) {
    if (obj.id == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "DELETE FROM RunConfigs \n"
        "WHERE run_config_id = $1;",
        obj.id);

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

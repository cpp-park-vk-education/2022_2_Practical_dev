#include "CodeSourceRepositoryImpl.hpp"

CodeSourceRepositoryImpl::CodeSourceRepositoryImpl() {
}

CodeSource CodeSourceRepositoryImpl::SelectById(const size_t& id) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "SELECT code_source_id, fk_run_config_id, source FROM CodeSources\n"
        "WHERE code_source_id = $1",
        id);

    CodeSource new_obj;
    new_obj.setId(std::atoi(res[0].c_str()));
    new_obj.setRunConfig(std::atoi(res[1].c_str()));
    new_obj.setSource(res[2].c_str());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));
    return new_obj;
}

std::vector<CodeSource> CodeSourceRepositoryImpl::SelectMany(const std::string& query, size_t n, size_t page) {
}

CodeSource CodeSourceRepositoryImpl::Insert(const CodeSource& obj) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "INSERT INTO CodeSources"
        "(fk_run_config_id,source)"
        "VALUES($1, $2)"
        "RETURNING code_source_id;",
        obj.getRunConfig(), obj.getSource());

    size_t id = std::atoi(res[0].c_str());
    CodeSource new_obj = obj;
    new_obj.setId(id);

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return new_obj;
}

int CodeSourceRepositoryImpl::Update(const CodeSource& obj) {
    if (obj.getId() == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "UPDATE CodeSources SET\n"
        "fk_run_config_id = $1, source = $2\n"
        "WHERE code_source_id = $3;",
        obj.getRunConfig(), obj.getSource(), obj.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

int CodeSourceRepositoryImpl::Delete(const CodeSource& obj) {
    if (obj.getId() == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "DELETE FROM RunConfigs \n"
        "WHERE run_config_id = $1;",
        obj.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

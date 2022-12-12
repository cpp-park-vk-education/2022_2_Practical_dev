#include "ImageRepositoryImpl.hpp"

ImageRepositoryImpl::ImageRepositoryImpl() {
}

Image ImageRepositoryImpl::SelectById(const size_t& id) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "SELECT image_id, fk_task_id, docker_id FROM Images\n"
        "WHERE image_id = $1",
        id);

    Image new_obj;
    new_obj.setId(std::atoi(res[0].c_str()));
    new_obj.setTaskId(std::atoi(res[1].c_str()));
    new_obj.setDockerId(res[2].c_str());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));
    return new_obj;
}

Image ImageRepositoryImpl::SelectByTaskId(const size_t& id) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "SELECT image_id, fk_task_id, docker_id FROM Images\n"
        "WHERE fk_task_id = $1",
        id);

    Image new_obj;
    new_obj.setId(std::atoi(res[0].c_str()));
    new_obj.setTaskId(std::atoi(res[1].c_str()));
    new_obj.setDockerId(res[2].c_str());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));
    return new_obj;
}

std::vector<Image> ImageRepositoryImpl::SelectMany(const std::string& query, size_t n, size_t page) {
    return std::vector<Image>();
}

Image ImageRepositoryImpl::Insert(const Image& obj) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "INSERT INTO Images"
        "(fk_task_id,docker_id)"
        "VALUES($1, $2)"
        "RETURNING image_id;",
        obj.getTaskId(), obj.getDockerId());

    size_t id = std::atoi(res[0].c_str());
    Image new_obj = obj;
    new_obj.setId(id);

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return new_obj;
}

int ImageRepositoryImpl::Update(const Image& obj) {
    if (obj.getId() == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "UPDATE Images SET\n"
        "fk_task_id = $1, docker_id = $2\n"
        "WHERE image_id = $3;",
        obj.getTaskId(), obj.getDockerId(), obj.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

int ImageRepositoryImpl::Delete(const Image& obj) {
    if (obj.getId() == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "DELETE FROM Images \n"
        "WHERE image_id = $1;",
        obj.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

#include "ParcelRepositoryImpl.hpp"

ParcelRepositoryImpl::ParcelRepositoryImpl() {
    manager = std::make_shared<DBManager>();
}

Parcel ParcelRepositoryImpl::SelectById(const size_t& id) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "SELECT parcel_id, fk_user_id, fk_task_id, fk_code_source_id, result, is_best, run_time,"
        "run_memory, failed_test, points FROM Parcels\n"
        "WHERE parcel_id = $1",
        id);

    Parcel new_obj;
    new_obj.setId(std::atoi(res[0].c_str()));
    new_obj.setUserId(std::atoi(res[1].c_str()));
    new_obj.setTaskId(std::atoi(res[2].c_str()));
    new_obj.setSourceCodeId(std::atoi(res[3].c_str()));
    new_obj.setResult(res[4].c_str());
    new_obj.setIfBest(res[5].c_str() == "true");
    new_obj.setRunTime(std::atoi(res[6].c_str()));
    new_obj.setRunMemory(std::atof(res[7].c_str()));
    new_obj.setFailedTest(std::atof(res[8].c_str()));
    new_obj.setPoints(std::atof(res[9].c_str()));

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));
    return new_obj;
}

std::vector<Parcel> ParcelRepositoryImpl::SelectMany(const std::string& query, size_t n, size_t page) {
}

Parcel ParcelRepositoryImpl::Insert(const Parcel& obj) {
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    pqxx::row res = worker->exec_params1(
        "INSERT INTO Parcels"
        "(fk_user_id, fk_task_id, fk_code_source_id, result, is_best, run_time, run_memory, failed_test, points)"
        "VALUES($1, $2, $3, $4, $5, $6, $7, $8, $9)"
        "RETURNING parcel_id;",
        obj.getUserId(), obj.getTaskId(), obj.getSourceCodeId(), obj.getResult(), obj.getIfBest(), obj.getRunTime(),
        obj.getRunMemory(), obj.getFailedTest(), obj.getPoints());

    size_t id = std::atoi(res[0].c_str());
    Parcel new_obj = obj;
    new_obj.setId(id);

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return new_obj;
}

int ParcelRepositoryImpl::Update(const Parcel& obj) {
    if (obj.getId() == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "UPDATE Parcels SET\n"
        "fk_user_id = $1, fk_task_id = $2, fk_code_source_id = $3, result = $4, is_best = $5, run_time = $6,\n"
        "run_memory = $7, failed_test = $8, points = $9\n"
        "WHERE parcel_id = $10;",
        obj.getUserId(), obj.getTaskId(), obj.getSourceCodeId(), obj.getResult(), obj.getIfBest(), obj.getRunTime(),
        obj.getRunMemory(), obj.getFailedTest(), obj.getPoints(), obj.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

int ParcelRepositoryImpl::Delete(const Parcel& obj) {
    if (obj.getId() == 0) {
        return 404;
    }

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec_params0(
        "DELETE FROM Parcels \n"
        "WHERE parcel_id = $1;",
        obj.getId());

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    return 0;
}

ParcelRepositoryImpl::~ParcelRepositoryImpl() {
}

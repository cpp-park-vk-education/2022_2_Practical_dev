#include "DBMigrations.hpp"

void dbmigrate::DropTables() {
    std::cerr << "Dropping existing tables...";

    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec0(
        "DROP TABLE IF EXISTS Users CASCADE;"
        "DROP TABLE IF EXISTS Contests CASCADE;"
        "DROP TABLE IF EXISTS User_Contests CASCADE;"
        "DROP TABLE IF EXISTS Parcels CASCADE;"
        "DROP TABLE IF EXISTS Tasks CASCADE;"
        "DROP TABLE IF EXISTS Comments CASCADE;"
        "DROP TABLE IF EXISTS Images CASCADE;"
        "DROP TABLE IF EXISTS CodeSources CASCADE;"
        "DROP TABLE IF EXISTS RunConfigs CASCADE;");

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    std::cerr << " OK" << std::endl;
}

void dbmigrate::SetupUserTable() {
    std::cerr << "Creating users table...";
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec0(
        "CREATE TABLE IF NOT EXISTS Users ("
        "user_id bigserial PRIMARY KEY NOT NULL,"
        "nickname varchar(255) NOT NULL,"
        "password varchar(255),"
        "email varchar(255)"
        ");");

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    std::cerr << " OK" << std::endl;
}

void dbmigrate::SetupContestTable() {
    std::cerr << "Creating contests table...";
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec0(
        "CREATE TABLE IF NOT EXISTS Contests ("
        "contest_id bigserial PRIMARY KEY NOT NULL,"
        "name varchar(255) NOT NULL,"
        "password varchar(255),"
        "description text,"
        "start_time bigint NOT NULL,"
        "end_time bigint NOT NULL"
        ");");

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    std::cerr << " OK" << std::endl;
}

void dbmigrate::SetupUserContestTable() {
    std::cerr << "Creating User-Contest table...";
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec0(
        "CREATE TABLE IF NOT EXISTS Users_Contests ("
        "id bigserial PRIMARY KEY NOT NULL,"
        "fk_contest_id bigint REFERENCES Contests(contest_id) NOT NULL,"
        "fk_user_id bigint REFERENCES Users(user_id) NOT NULL,"
        "is_admin boolean NOT NULL DEFAULT false"
        ");");

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    std::cerr << " OK" << std::endl;
}

void dbmigrate::SetupTaskTable() {
    std::cerr << "Creating tasks table...";
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec0(
        "CREATE TABLE IF NOT EXISTS Tasks ("
        "task_id bigserial PRIMARY KEY NOT NULL,"
        "fk_contest_id bigint REFERENCES Contests(contest_id) NOT NULL,"
        "name varchar(255) NOT NULL,"
        "description text,"
        "cost bigint,"
        "memory_limit float,"
        "time_limit int"
        ");");

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    std::cerr << " OK" << std::endl;
}

void dbmigrate::SetupImageTable() {
    std::cerr << "Creating images table...";
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec0(
        "CREATE TABLE IF NOT EXISTS Images ("
        "image_id bigserial PRIMARY KEY NOT NULL,"
        "fk_task_id bigint REFERENCES Tasks(task_id) NOT NULL,"
        "docker_id varchar(255) NOT NULL"
        ");");

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    std::cerr << " OK" << std::endl;
}

void dbmigrate::SetupRunConfigTable() {
    std::cerr << "Creating run configs table...";
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec0(
        "CREATE TABLE IF NOT EXISTS RunConfigs ("
        "run_config_id bigserial PRIMARY KEY NOT NULL,"
        "name varchar(255) NOT NULL,"
        "compiler varchar(255) NOT NULL,"
        "compiler_flags text,"
        "interpreter varchar(255) NOT NULL,"
        "interpreter_flags text"
        ");");

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    std::cerr << " OK" << std::endl;
}

void dbmigrate::SetupCodeSourceTable() {
    std::cerr << "Creating code sources table...";
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec0(
        "CREATE TABLE IF NOT EXISTS CodeSources ("
        "code_source_id bigserial PRIMARY KEY NOT NULL,"
        "fk_run_config_id bigint REFERENCES RunConfigs(run_config_id) NOT NULL,"
        "source text NOT NULL"
        ");");

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    std::cerr << " OK" << std::endl;
}

void dbmigrate::SetupParcelTable() {
    std::cerr << "Creating parcels table...";
    std::unique_ptr<pqxx::work> worker = DBManager::getInstance().GetFreeWorker();

    worker->exec0(
        "CREATE TABLE IF NOT EXISTS Parcels ("
        "parcel_id bigserial PRIMARY KEY NOT NULL,"
        "fk_user_id bigint REFERENCES Users(user_id) NOT NULL,"
        "fk_task_id bigint REFERENCES Tasks(task_id) NOT NULL,"
        "fk_code_source_id bigint REFERENCES CodeSources(code_source_id) NOT NULL,"
        "result varchar(10) NOT NULL,"
        "is_best bool NOT NULL DEFAULT false,"
        "run_time bigint,"
        "run_memory float,"
        "failed_test int DEFAULT 0,"
        "points int"
        ");");

    worker->commit();

    DBManager::getInstance().ReturnWorker(std::move(worker));

    std::cerr << " OK" << std::endl;
}

void dbmigrate::DropAndMigrateAll() {
    DropTables();

    SetupUserTable();
    SetupContestTable();
    SetupUserContestTable();
    SetupTaskTable();
    SetupImageTable();
    SetupRunConfigTable();
    SetupCodeSourceTable();
    SetupParcelTable();
}

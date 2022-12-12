#include <iostream>
#include <pqxx/pqxx>

#include "DBManager.hpp"

namespace dbmigrate {
void DropTables();

void SetupUserTable();

void SetupContestTable();

void SetupUserContestTable();

void SetupTaskTable();

void SetupImageTable();

void SetupRunConfigTable();

void SetupCodeSourceTable();

void SetupParcelTable();

void DropAndMigrateAll();
}  // namespace dbmigrate

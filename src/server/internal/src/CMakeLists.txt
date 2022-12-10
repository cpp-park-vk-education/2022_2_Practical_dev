add_subdirectory(entities)
add_subdirectory(db)
add_subdirectory(checker)
add_subdirectory(runner)
add_subdirectory(taskcreator)

add_subdirectory(acceptor)
add_subdirectory(connection)
add_subdirectory(connection_manager)
add_subdirectory(parser)
add_subdirectory(router)
add_subdirectory(server)

set(DB_Lib_LIB ${DB_Lib_LIB} PARENT_SCOPE)
set(DB_Lib_INCLUDE_DIRS ${DB_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Runner_Lib_LIB ${Runner_Lib_LIB} PARENT_SCOPE)
set(Runner_Lib_INCLUDE_DIRS ${Runner_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Checker_Lib_LIB ${Checker_Lib_LIB} PARENT_SCOPE)
set(Checker_Lib_INCLUDE_DIRS ${Checker_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Entities_Lib_LIB ${Entities_Lib_LIB} PARENT_SCOPE)
set(Entities_Lib_INCLUDE_DIRS ${Entities_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(TaskCreator_Lib_LIB ${TaskCreator_Lib_LIB} PARENT_SCOPE)
set(TaskCreator_Lib_INCLUDE_DIRS ${TaskCreator_Lib_INCLUDE_DIRS} PARENT_SCOPE)


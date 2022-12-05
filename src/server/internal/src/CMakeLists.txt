add_subdirectory(db)

set(DB_Lib_LIB ${DB_Lib_LIB} PARENT_SCOPE)
set(DB_Lib_INCLUDE_DIRS ${DB_Lib_INCLUDE_DIRS} PARENT_SCOPE)

add_subdirectory(acceptor)
add_subdirectory(connection)
add_subdirectory(connection_manager)
add_subdirectory(parser)
add_subdirectory(router)
add_subdirectory(server)
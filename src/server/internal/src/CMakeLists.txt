# add_subdirectory(entities)
# add_subdirectory(db)
# add_subdirectory(checker)
# add_subdirectory(runner)
# add_subdirectory(taskcreator)

add_subdirectory(acceptor)
target_include_directories(acceptor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(connection)
target_include_directories(connection PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# add_subdirectory(connection_manager)
# add_subdirectory(parser)
# add_subdirectory(router)
add_subdirectory(server)
target_include_directories(server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(utils)
target_include_directories(namespaces INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# set(DB_Lib_LIB ${DB_Lib_LIB} PARENT_SCOPE)
# set(DB_Lib_INCLUDE_DIRS ${DB_Lib_INCLUDE_DIRS} PARENT_SCOPE)

# set(Runner_Lib_LIB ${Runner_Lib_LIB} PARENT_SCOPE)
# set(Runner_Lib_INCLUDE_DIRS ${Runner_Lib_INCLUDE_DIRS} PARENT_SCOPE)

# set(Checker_Lib_LIB ${Checker_Lib_LIB} PARENT_SCOPE)
# set(Checker_Lib_INCLUDE_DIRS ${Checker_Lib_INCLUDE_DIRS} PARENT_SCOPE)

# set(Entities_Lib_LIB ${Entities_Lib_LIB} PARENT_SCOPE)
# set(Entities_Lib_INCLUDE_DIRS ${Entities_Lib_INCLUDE_DIRS} PARENT_SCOPE)

# set(TaskCreator_Lib_LIB ${TaskCreator_Lib_LIB} PARENT_SCOPE)
# set(TaskCreator_Lib_INCLUDE_DIRS ${TaskCreator_Lib_INCLUDE_DIRS} PARENT_SCOPE)


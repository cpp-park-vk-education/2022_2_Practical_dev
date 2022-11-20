cmake_minimum_required(VERSION 3.10)

add_subdirectory(src)
add_subdirectory(parcels)
add_subdirectory(users)
add_subdirectory(tasks)
add_subdirectory(comments)
add_subdirectory(contests)
add_subdirectory(codesources)
add_subdirectory(runconfigs)

set(DB_Lib_LIB ${DB_Lib_LIB} PARENT_SCOPE)
set(DB_Lib_INCLUDE_DIRS ${DB_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Runner_Lib_LIB ${Runner_Lib_LIB} PARENT_SCOPE)
set(Runner_Lib_INCLUDE_DIRS ${Runner_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Checker_Lib_LIB ${Checker_Lib_LIB} PARENT_SCOPE)
set(Checker_Lib_INCLUDE_DIRS ${Checker_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Entities_Lib_LIB ${Entities_Lib_LIB} PARENT_SCOPE)
set(Entities_Lib_INCLUDE_DIRS ${Entities_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Parcel_Lib_LIB ${Parcel_Lib_LIB} PARENT_SCOPE)
set(Parcel_Lib_INCLUDE_DIRS ${Parcel_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(User_Lib_LIB ${User_Lib_LIB} PARENT_SCOPE)
set(User_Lib_INCLUDE_DIRS ${User_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Comment_Lib_LIB ${Comment_Lib_LIB} PARENT_SCOPE)
set(Comment_Lib_INCLUDE_DIRS ${Comment_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Contest_Lib_LIB ${Contest_Lib_LIB} PARENT_SCOPE)
set(Contest_Lib_INCLUDE_DIRS ${Contest_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Task_Lib_LIB ${Task_Lib_LIB} PARENT_SCOPE)
set(Task_Lib_INCLUDE_DIRS ${Task_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Run_Config_Lib_LIB ${Run_Config_Lib_LIB} PARENT_SCOPE)
set(Run_Config_Lib_INCLUDE_DIRS ${Run_Config_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(Code_Source_Lib_LIB ${Code_Source_Lib_LIB} PARENT_SCOPE)
set(Code_Source_Lib_INCLUDE_DIRS ${Code_Source_Lib_INCLUDE_DIRS} PARENT_SCOPE)

set(TaskCreator_Lib_LIB ${TaskCreator_Lib_LIB} PARENT_SCOPE)
set(TaskCreator_Lib_INCLUDE_DIRS ${TaskCreator_Lib_INCLUDE_DIRS} PARENT_SCOPE)


cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)


enable_testing()
add_subdirectory(internal)

# message("\n\n")

# message("DB_Lib_LIB = ${DB_Lib_LIB}")
# message("DB_Lib_INCLUDE_DIRS = ${DB_Lib_INCLUDE_DIRS}")

# message("Runner_Lib_LIB = ${Runner_Lib_LIB}")
# message("Runner_Lib_INCLUDE_DIRS = ${Runner_Lib_INCLUDE_DIRS}")

# message("Checker_Lib_LIB = ${Checker_Lib_LIB}")
# message("Checker_Lib_INCLUDE_DIRS = ${Checker_Lib_INCLUDE_DIRS}")

# message("Entities_Lib_LIB = ${Entities_Lib_LIB}")
# message("Entities_Lib_INCLUDE_DIRS = ${Entities_Lib_INCLUDE_DIRS}")

# message("Parcel_Lib_LIB = ${Parcel_Lib_LIB}")
# message("Parcel_Lib_INCLUDE_DIRS = ${Parcel_Lib_INCLUDE_DIRS}")

# message("User_Lib_LIB = ${User_Lib_LIB}")
# message("User_Lib_INCLUDE_DIRS = ${User_Lib_INCLUDE_DIRS}")

# message("Comment_Lib_LIB = ${Comment_Lib_LIB}")
# message("Comment_Lib_INCLUDE_DIRS = ${Comment_Lib_INCLUDE_DIRS}")

# message("Contest_Lib_LIB = ${Contest_Lib_LIB}")
# message("Contest_Lib_INCLUDE_DIRS = ${Contest_Lib_INCLUDE_DIRS}")

# message("Task_Lib_LIB = ${Task_Lib_LIB}")
# message("Task_Lib_INCLUDE_DIRS = ${Task_Lib_INCLUDE_DIRS}")

# message("TaskCreator_Lib_LIB = ${TaskCreator_Lib_LIB}")
# message("TaskCreator_Lib_INCLUDE_DIRS = ${TaskCreator_Lib_INCLUDE_DIRS}")

# message("Run_Config_Lib_LIB = ${Run_Config_Lib_LIB}")
# message("Run_Config_Lib_INCLUDE_DIRS = ${Run_Config_Lib_INCLUDE_DIRS}")

# message("Code_Source_Lib_LIB = ${Code_Source_Lib_LIB}")
# message("Code_Source_Lib_INCLUDE_DIRS = ${Code_Source_Lib_INCLUDE_DIRS}")


add_subdirectory(cmd)
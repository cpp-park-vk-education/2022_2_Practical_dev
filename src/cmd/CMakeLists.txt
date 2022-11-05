cmake_minimum_required(VERSION 3.10)

if((BUILD_MODE STREQUAL ${BUILD_SERVER}) OR (BUILD_MODE STREQUAL ${BUILD_ALL}))
    add_subdirectory(client)
endif()
if((BUILD_MODE STREQUAL ${BUILD_CLIENT}) OR (BUILD_MODE STREQUAL ${BUILD_ALL}) OR True)
    add_subdirectory(server)
endif()

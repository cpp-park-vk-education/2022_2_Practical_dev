cmake_minimum_required(VERSION 3.10)
project(what_a_contest_gui)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -pedantic -Wformat=2 -Wfloat-equal -Wconversion -std=c++17 \
    -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align")

include_directories(include/ widgets/ navigator/ fragments/ screensfactory/)

#add_subdirectory(network)

#set(NETWORK_Lib_LIB ${NETWORK_Lib_LIB} PARENT_SCOPE)
#set(NETWORK_Lib_INCLUDE_DIRS ${NETWORK_Lib_INCLUDE_DIRS} PARENT_SCOPE)

include_directories(include/)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/*.hpp *.h widgets/*.hpp navigator/*.hpp fragments/*.hpp screensfactory/*.hpp)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)

QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp widgets/*.cpp navigator/*.cpp fragments/*.cpp)

#add_executable(what_a_contest_gui ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
add_library(what_a_contest_gui STATIC ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(what_a_contest_gui Qt5::Widgets)
ENABLE_TESTING()
ADD_SUBDIRECTORY(tests)

cmake_minimum_required(VERSION 3.11)

set (MY_PROJECTNAME cpp_skeleton)

project(${MY_PROJECTNAME} LANGUAGES CXX)

set (EXTERN_DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern)

# Provide path for scripts
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake")

include(warnings)
include(MunkeiVersionFromGit)
#include(CppResultType)

## it spams the target list in CLion
#include(CTestConfig)
#include(CTest)
#enable_testing()

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib)
add_subdirectory(Tests)
set(SOURCE_FILES main.cpp )
add_executable(${MY_PROJECTNAME} ${SOURCE_FILES})
target_link_libraries (${MY_PROJECTNAME} LINK_PUBLIC lib)
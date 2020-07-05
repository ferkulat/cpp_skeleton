cmake_minimum_required(VERSION 3.14)
set(CMAKE_VERBOSE_MAKEFILE ON)
project(cpp_skeleton LANGUAGES CXX)


set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})

#include(MunkeiVersionFromGit)
#include(msvc_cplusplus)
include(catch2)
#include(CTestConfig)
include(CTest)
include(warnings)
#include(checkedcmd)
#include(CppSkilledType)
#include(CppResultType)

enable_testing()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(mylib)
add_subdirectory(Tests)
set(SOURCE_FILES main.cpp )
add_executable(cpp_skeleton ${SOURCE_FILES})
target_link_libraries (cpp_skeleton LINK_PUBLIC mylib)

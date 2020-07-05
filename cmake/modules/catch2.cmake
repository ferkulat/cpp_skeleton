cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

include(FetchContent)
set(component catch2)
# ------------------------------------------------------------------------------
# A modern, C++-native, header-only, test framework for unit-tests,
# TDD and BDD - using C++11, C++14, C++17 and later
FetchContent_Declare(
        extern_${component}
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.12.4
        GIT_SHALLOW true
)

FetchContent_GetProperties(extern_${component})
if(NOT extern_${component}_POPULATED)
  FetchContent_Populate(extern_${component})
    add_subdirectory(
    ${extern_${component}_SOURCE_DIR}
    ${extern_${component}_BINARY_DIR}
    EXCLUDE_FROM_ALL)

endif()
#include_directories(SYSTEM ${EXTERN_CATCH_HEADER_DIR})
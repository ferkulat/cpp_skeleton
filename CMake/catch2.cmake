cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

include(FetchContent)

# ------------------------------------------------------------------------------
# A modern, C++-native, header-only, test framework for unit-tests,
# TDD and BDD - using C++11, C++14, C++17 and later
FetchContent_Declare(
  extern_catch2
  DOWNLOAD_NO_EXTRACT true
  DOWNLOAD URL        https://github.com/catchorg/Catch2/releases/download/v2.7.1/catch.hpp
  DOWNLOAD_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/extern
)

FetchContent_GetProperties(extern_catch2)
if(NOT extern_catch2_POPULATED)
  FetchContent_Populate(extern_catch2)
endif()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/extern)
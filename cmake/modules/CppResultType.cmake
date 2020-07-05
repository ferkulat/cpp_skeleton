cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
include(FetchContent)


FetchContent_Declare(
  cppresulttype
  GIT_REPOSITORY https://github.com/ferkulat/CppResultType.git
  GIT_TAG        6de4dfaa2a0d887deeaa6a329a0d2ed77b44280a
)
if(NOT cppresulttype_POPULATED)
    FetchContent_Populate(cppresulttype)
endif()
include_directories(SYSTEM ${cppresulttype_SOURCE_DIR}/include )


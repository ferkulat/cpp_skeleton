cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(
  cppresulttype
  GIT_REPOSITORY https://github.com/ferkulat/CppResultType.git
  GIT_TAG        master
  SOURCE_DIR     ${EXTERN_DEPENDENCIES_DIR}/cppresulttype
)
FetchContent_GetProperties(cppresulttype)
if(NOT cppresulttype_POPULATED)
    FetchContent_Populate(cppresulttype)
endif()
include_directories(${cppresulttype_SOURCE_DIR}/include )

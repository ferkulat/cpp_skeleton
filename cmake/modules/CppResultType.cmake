cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(cppresulttype
  GIT_REPOSITORY https://github.com/ferkulat/CppResultType.git
  GIT_TAG        cd031e5be41b98876cb1d9d855838a045c624d62
)
FetchContent_MakeAvailable(cppresulttype)

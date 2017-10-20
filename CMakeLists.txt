cmake_minimum_required(VERSION 3.7)
project(catch)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib)
add_subdirectory(Tests)
set(SOURCE_FILES main.cpp )
add_executable(catch ${SOURCE_FILES})
target_link_libraries (catch LINK_PUBLIC lib)
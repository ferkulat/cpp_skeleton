add_library(mylib fun.cpp fun.h)

target_include_directories (mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
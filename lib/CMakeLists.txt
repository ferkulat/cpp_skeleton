add_library(lib fun.cpp fun.h)

target_include_directories (lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
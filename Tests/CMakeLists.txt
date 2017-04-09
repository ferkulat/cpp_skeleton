
set(SOURCE_FILES TestMain.cpp Test_1.cpp)
add_executable(tests ${SOURCE_FILES})
target_link_libraries (tests LINK_PUBLIC lib)
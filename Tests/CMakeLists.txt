
set(SOURCE_FILES TestMain.cpp Test_1.cpp Test_compose.cpp catch.hpp Test_MultiPredicate.cpp)
add_executable(tests ${SOURCE_FILES})
target_link_libraries (tests LINK_PUBLIC lib)

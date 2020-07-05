include(catch2)
#set(EXTERN_DOCTEST_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/doctest)
#include(doctest)
set(SOURCE_FILES TestMain.cpp Test_1.cpp)
add_executable(tests ${SOURCE_FILES})
target_link_libraries (tests LINK_PUBLIC lib Catch2::Catch2)
add_test(
        NAME tests
        COMMAND tests
)

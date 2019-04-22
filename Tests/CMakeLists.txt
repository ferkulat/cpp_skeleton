include(catch2)
set(SOURCE_FILES TestMain.cpp Test_1.cpp)
add_executable(tests ${SOURCE_FILES})
target_link_libraries (tests LINK_PUBLIC lib)
add_test(
        NAME tests
        COMMAND "${CMAKE_CTEST_COMMAND}"
)

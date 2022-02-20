add_executable(demo_test demo_test.cpp)
target_link_libraries(demo_test gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(demo_test)

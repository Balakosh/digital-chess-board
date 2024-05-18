# Link test executable against gtest & gtest_main
add_executable(runTests hello_test.cc)
target_link_libraries(runTests gtest gtest_main pthread YourLibrary)

# Add the test to CTest
add_test(NAME ExampleTest COMMAND runTests)
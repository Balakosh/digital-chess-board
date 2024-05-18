# Link test executable against gtest & gtest_main
add_executable(runTests hello_test.cc)
target_link_libraries(runTests gtest gtest_main pthread YourLibrary)

if(WIN32)
    target_link_libraries(runTests gtest gtest_main YourLibrary)
else()
    target_link_libraries(runTests gtest gtest_main pthread YourLibrary)
endif()

# Add the test to CTest
add_test(NAME ExampleTest COMMAND runTests)
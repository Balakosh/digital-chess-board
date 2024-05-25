# test/CMakeLists.txt

# Include GoogleTest
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Link test executable against gtest & gtest_main
add_executable(runTests
        hello_test.cc
        pgn_test.cc
        piece_to_string_converter_test.cc
)
target_link_libraries(runTests gtest gtest_main pthread digital-chess-board-lib)

# Add the test to CTest
add_test(NAME runTests COMMAND runTests)

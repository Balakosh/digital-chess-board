cmake_minimum_required(VERSION 3.26)
project(digital-chess-board)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(${CMAKE_PROJECT_NAME} main.cpp
        test/hello_test.cc)

add_subdirectory("thirdparty/googletest")

enable_testing()

add_executable(
        hello_test
        test/hello_test.cc
)
target_link_libraries(
        hello_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)


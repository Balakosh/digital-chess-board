cmake_minimum_required(VERSION 3.22)
project(digital-chess-board)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)

enable_testing()
add_subdirectory(thirdparty/googletest)
add_subdirectory(test)

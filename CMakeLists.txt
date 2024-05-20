cmake_minimum_required(VERSION 3.22)
project(digital-chess-board)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

# Add the src directory
add_subdirectory(src)

# Add the tests directory
enable_testing()
add_subdirectory(thirdparty/googletest)
add_subdirectory(test)

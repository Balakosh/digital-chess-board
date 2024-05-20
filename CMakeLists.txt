cmake_minimum_required(VERSION 3.22)
project(digital-chess-board)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

include_directories(include thirdparty/Stockfish/src)

# Add the src directory
add_subdirectory(src)

# Add the tests directory
enable_testing()
add_subdirectory(thirdparty/googletest)
add_subdirectory(test)

message(STATUS "${CMAKE_SOURCE_DIR}/thirdparty/Stockfish/src")

include(ExternalProject)

# Specify the shell to use for building Stockfish
set(ENV{SHELL} /bin/sh)

ExternalProject_Add(
        stockfish
        SOURCE_DIR ${CMAKE_SOURCE_DIR}/thirdparty/Stockfish/src
        CONFIGURE_COMMAND ""
        BUILD_COMMAND /bin/sh -c "/usr/bin/make -j ARCH=x86-64-avx2"
        INSTALL_COMMAND ""
        BUILD_IN_SOURCE 1
        LOG_BUILD ON  # Capture the build log for debugging
)

# Ensure stockfish target is built before the main project
add_dependencies(digital-chess-board stockfish)

# Custom target to ensure Stockfish build
add_custom_target(build_stockfish ALL
        COMMAND /bin/sh -c "/usr/bin/make -C ${CMAKE_SOURCE_DIR}/thirdparty/Stockfish/src -j ARCH=x86-64-avx2"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/thirdparty/Stockfish/src
        BYPRODUCTS ${CMAKE_SOURCE_DIR}/thirdparty/Stockfish/src/stockfish
)

# Add dependency to the stockfish custom target
add_dependencies(digital-chess-board build_stockfish)

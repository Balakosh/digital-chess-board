cmake_minimum_required(VERSION 3.26)
project(digital-chess-board)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

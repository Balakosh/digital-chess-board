# src/CMakeLists.txt

# Gather source files for your project
set(SOURCES
        main.cpp
        # Add other project-specific source files here if needed
)

# Add Stockfish source files
file(GLOB_RECURSE STOCKFISH_SOURCES
        ${CMAKE_SOURCE_DIR}/thirdparty/Stockfish/src/*.cpp
)

list(FILTER STOCKFISH_SOURCES EXCLUDE REGEX ".*main.cpp")

# Combine all sources
list(APPEND SOURCES ${STOCKFISH_SOURCES})

# Include directories for your project
include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/thirdparty/Stockfish/src
)

# Add the executable target
add_executable(digital-chess-board ${SOURCES})

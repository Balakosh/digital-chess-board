# src/CMakeLists.txt

# Gather source files for your project
set(SOURCES
        main.cpp
        ../include/pgn.h
        pgn.cpp
        piece_to_string_converter.cpp
        ../include/piece_to_string_converter.h
        square_to_string_converter.cpp
        ../include/square_to_string_converter.h
        file_to_string_converter.cpp
        ../include/file_to_string_converter.h
        rank_to_string_converter.cpp
        ../include/rank_to_string_converter.h
        lichess.cpp
        ../include/lichess.h
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

# Add the library target
add_library(digital-chess-board-lib ${SOURCES})

# Find and link the cURL package
find_package(CURL REQUIRED)
target_link_libraries(digital-chess-board-lib CURL::libcurl)

# Add the executable target
add_executable(digital-chess-board main.cpp)

# Link the executable to your library
target_link_libraries(digital-chess-board digital-chess-board-lib)
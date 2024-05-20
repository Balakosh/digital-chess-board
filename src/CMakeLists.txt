# src/CMakeLists.txt
add_executable(digital-chess-board main.cpp)  # Adjust this to your actual source files

# Assuming Stockfish produces a static library or an executable
# Update this based on the actual output of Stockfish build
set(STOCKFISH_LIB ${CMAKE_SOURCE_DIR}/thirdparty/Stockfish/src/stockfish)  # Adjust if necessary

# Link Stockfish library or executable if needed
# For example, if Stockfish produces a static library:
# target_link_libraries(digital-chess-board ${STOCKFISH_LIB})

# Or if you need to ensure the Stockfish executable is available:
add_custom_command(TARGET digital-chess-board POST_BUILD
        COMMAND ${STOCKFISH_LIB} ARGS ...
)

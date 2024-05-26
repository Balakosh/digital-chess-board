#include <gtest/gtest.h>

#include "../include/pgn.h"
#include "../thirdparty/Stockfish/src/types.h"

TEST(PGNTest, move_to_string_test) {
    Stockfish::Position pos = {};
    Stockfish::StateInfo si = {};

    Stockfish::Bitboards::init();
    Stockfish::Position::init();

    std::string start_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    pos.set(start_position, false, &si);

    const std::string move = pgn::move_to_string(Stockfish::Square::SQ_E2, Stockfish::Square::SQ_E4, pos);

    ASSERT_EQ("e4", move);
}
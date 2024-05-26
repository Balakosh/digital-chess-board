#include <gtest/gtest.h>

#include "../include/pgn.h"
#include "../thirdparty/Stockfish/src/types.h"

class PGNTest : public ::testing::Test {
protected:
    Stockfish::Position pos;
    Stockfish::StateInfo si;

    void SetUp() override {
        Stockfish::Bitboards::init();
        Stockfish::Position::init();

        std::string start_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        pos.set(start_position, false, &si);
    }

    void TearDown() override {
    }
};

TEST_F(PGNTest, Pawn_to_e4) {
    const std::string move = pgn::move_to_string(Stockfish::Square::SQ_E2, Stockfish::Square::SQ_E4, pos);

    ASSERT_EQ("e4", move);
}

TEST_F(PGNTest, Pawn_to_d4) {
    const std::string move = pgn::move_to_string(Stockfish::Square::SQ_D2, Stockfish::Square::SQ_D4, pos);

    ASSERT_EQ("d4", move);
}

TEST_F(PGNTest, Knight_f3) {
    const std::string move = pgn::move_to_string(Stockfish::Square::SQ_G1, Stockfish::Square::SQ_F3, pos);

    ASSERT_EQ("Nf3", move);
}

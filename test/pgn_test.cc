#include <gtest/gtest.h>
#include <string>

#include "../include/pgn.h"
#include "../thirdparty/Stockfish/src/types.h"

struct PGNTestParams {
    Stockfish::Square from;
    Stockfish::Square to;
    std::string expected_move;
};

class PGNTest : public ::testing::TestWithParam<PGNTestParams> {
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

TEST_P(PGNTest, MoveToStringTest) {
    const auto& params = GetParam();
    const std::string move = pgn::move_to_string(params.from, params.to, pos);

    ASSERT_EQ(params.expected_move, move);
}

INSTANTIATE_TEST_SUITE_P(
        PGNTests,
        PGNTest,
        ::testing::Values(
                PGNTestParams{Stockfish::Square::SQ_E2, Stockfish::Square::SQ_E4, "e4"},
                PGNTestParams{Stockfish::Square::SQ_D2, Stockfish::Square::SQ_D4, "d4"},
                PGNTestParams{Stockfish::Square::SQ_G1, Stockfish::Square::SQ_F3, "Nf3"},
                PGNTestParams{Stockfish::Square::SQ_B1, Stockfish::Square::SQ_C3, "Nc3"}
        )
);
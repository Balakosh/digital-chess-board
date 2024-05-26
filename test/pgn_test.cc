#include <gtest/gtest.h>
#include <string>

#include "../include/pgn.h"
#include "../thirdparty/Stockfish/src/types.h"

struct PGNTestParams {
    std::string fen_position;
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
    }

    void TearDown() override {
    }
};

TEST_P(PGNTest, MoveToStringTest) {
    const auto& params = GetParam();
    pos.set(params.fen_position, false, &si);

    const std::string move = pgn::move_to_string(params.from, params.to, pos);

    ASSERT_EQ(params.expected_move, move);
}

INSTANTIATE_TEST_SUITE_P(
        PGNTests,
        PGNTest,
        ::testing::Values(
                PGNTestParams{"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", Stockfish::Square::SQ_E2, Stockfish::Square::SQ_E4, "e4"},
                PGNTestParams{"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", Stockfish::Square::SQ_D2, Stockfish::Square::SQ_D4, "d4"},
                PGNTestParams{"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", Stockfish::Square::SQ_G1, Stockfish::Square::SQ_F3, "Nf3"},
                PGNTestParams{"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", Stockfish::Square::SQ_B1, Stockfish::Square::SQ_C3, "Nc3"},
                PGNTestParams{"rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1", Stockfish::Square::SQ_G8, Stockfish::Square::SQ_F6, "Nf6"}
        )
);
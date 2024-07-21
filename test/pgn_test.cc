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
                PGNTestParams{"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", Stockfish::Square::SQ_A1, Stockfish::Square::SQ_H8, "illegal move!"},
                PGNTestParams{"rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1", Stockfish::Square::SQ_G8, Stockfish::Square::SQ_F6, "Nf6"},
                PGNTestParams{"rnbqkb1r/pppppppp/5n2/8/4P3/8/PPPP1PPP/RNBQKBNR w KQkq - 1 2", Stockfish::Square::SQ_F1, Stockfish::Square::SQ_C4, "Bc4"},
                PGNTestParams{"rnbqkb1r/pppppppp/5n2/8/2B1P3/8/PPPP1PPP/RNBQK1NR b KQkq - 2 2", Stockfish::Square::SQ_H8, Stockfish::Square::SQ_G8, "Rg8"},
                PGNTestParams{"rnbqkbr1/pppppppp/5n2/8/2B1P3/8/PPPP1PPP/RNBQK1NR w KQq - 3 3", Stockfish::Square::SQ_E1, Stockfish::Square::SQ_F1, "Kf1"},
                PGNTestParams{"rnbqkbr1/pppppppp/5n2/8/2B1P3/8/PPPP1PPP/RNBQ1KNR b q - 4 3", Stockfish::Square::SQ_F6, Stockfish::Square::SQ_E4, "Nxe4"},
                PGNTestParams{"rnbqkbr1/pppppppp/8/8/2B1n3/8/PPPP1PPP/RNBQ1KNR w q - 0 4", Stockfish::Square::SQ_D1, Stockfish::Square::SQ_F3, "Qf3"},
                PGNTestParams{"rnbqkbr1/pppppppp/8/8/2B1n3/5Q2/PPPP1PPP/RNB2KNR b q - 1 4", Stockfish::Square::SQ_E4, Stockfish::Square::SQ_F2, "Nxf2"},
                PGNTestParams{"rnbqkbr1/pppppppp/8/8/2B5/5Q2/PPPP1nPP/RNB2KNR w q - 0 5", Stockfish::Square::SQ_F3, Stockfish::Square::SQ_F2, "Qxf2"},
                // special moves
                // castling
                PGNTestParams{"r2qkbnr/ppp1pppp/2n5/1B1p4/4P1b1/5N2/PPPP1PPP/RNBQK2R w KQkq - 4 4", Stockfish::Square::SQ_E1, Stockfish::Square::SQ_G1, "O-O"},
                PGNTestParams{"r3kbnr/pppqpppp/2n5/1B1p4/4P1b1/5N2/PPPP1PPP/RNBQR1K1 b kq - 7 5", Stockfish::Square::SQ_E8, Stockfish::Square::SQ_C8, "O-O-O"},
                PGNTestParams{"5k2/8/8/8/8/8/8/4K2R w K - 0 1", Stockfish::Square::SQ_E1, Stockfish::Square::SQ_G1, "O-O+"},
                // en passant
                PGNTestParams{"rnbqkbnr/1pp1pppp/8/p2pP3/8/8/PPPP1PPP/RNBQKBNR w KQkq d6 0 3", Stockfish::Square::SQ_E5, Stockfish::Square::SQ_D6, "exd6"},
                // ambiguous moves
                PGNTestParams{"rnbqkb1r/pppp1ppp/5n2/4p3/4P3/8/PPPPNPPP/RNBQKB1R w KQkq - 2 3", Stockfish::Square::SQ_E2, Stockfish::Square::SQ_C3, "Nec3"},
                PGNTestParams{"r2qr1k1/pppbbppp/2np1n2/1B2p3/4P3/2NP1N2/PPPBQPPP/R4RK1 w - - 5 9", Stockfish::Square::SQ_F1, Stockfish::Square::SQ_E1, "Rfe1"},
                PGNTestParams{"7k/R7/8/8/8/8/R7/7K w - - 0 1", Stockfish::Square::SQ_A7, Stockfish::Square::SQ_A5, "R7a5"},
                // Check
                PGNTestParams{"rnb1kbnr/ppp1pppp/8/3q4/8/2N5/PPPP1PPP/R1BQKBNR b KQkq - 1 3", Stockfish::Square::SQ_D5, Stockfish::Square::SQ_E5, "Qe5+"},
                PGNTestParams{"rnb1kb1r/ppp1pppp/8/4q3/6n1/2N2N2/PPPPBPPP/R1BQ1RK1 b kq - 7 6", Stockfish::Square::SQ_E5, Stockfish::Square::SQ_H2, "Qxh2+"},
                PGNTestParams{"rnb1kb1r/ppp1pppp/8/3N4/6n1/8/PPPPBPP1/R1BQ1RK1 w kq - 2 9", Stockfish::Square::SQ_D5, Stockfish::Square::SQ_C7, "Nxc7+"},
                //Promotion
                PGNTestParams{"8/P6k/8/8/8/8/1p5K/8 w - - 0 1", Stockfish::Square::SQ_A7, Stockfish::Square::SQ_A8, "a8=Q"},
                PGNTestParams{"7k/3P4/8/8/8/8/6K1/8 w - - 0 1", Stockfish::Square::SQ_D7, Stockfish::Square::SQ_D8, "d8=Q+"}
        )
);
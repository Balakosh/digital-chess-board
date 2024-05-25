#include <gtest/gtest.h>

#include "../include/piece_to_string_converter.h"
#include "../thirdparty/Stockfish/src/types.h"

struct PieceToStringTestParams {
    Stockfish::Piece piece;
    std::string expected_string;
};

class PieceToStringConverterTest : public ::testing::TestWithParam<PieceToStringTestParams> {};

TEST_P(PieceToStringConverterTest, Convert) {
    PieceToStringTestParams params = GetParam();

    const std::string piece_str = piece_to_string_converter::convert(params.piece);

    EXPECT_EQ(piece_str, params.expected_string);
}

INSTANTIATE_TEST_SUITE_P(
        PieceToStringTests,
        PieceToStringConverterTest,
        ::testing::Values(
                PieceToStringTestParams{Stockfish::W_ROOK, "R"},
                PieceToStringTestParams{Stockfish::W_KNIGHT, "N"},
                PieceToStringTestParams{Stockfish::W_BISHOP, "B"},
                PieceToStringTestParams{Stockfish::W_QUEEN, "Q"},
                PieceToStringTestParams{Stockfish::W_KING, "K"},
                PieceToStringTestParams{Stockfish::W_PAWN, ""},
                PieceToStringTestParams{Stockfish::B_ROOK, "R"},
                PieceToStringTestParams{Stockfish::B_KNIGHT, "N"},
                PieceToStringTestParams{Stockfish::B_BISHOP, "B"},
                PieceToStringTestParams{Stockfish::B_QUEEN, "Q"},
                PieceToStringTestParams{Stockfish::B_KING, "K"},
                PieceToStringTestParams{Stockfish::B_PAWN, ""}
        )
);
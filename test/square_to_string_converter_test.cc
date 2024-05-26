#include <gtest/gtest.h>

#include "../include/square_to_string_converter.h"
#include "../thirdparty/Stockfish/src/types.h"

struct SquareToStringConverterTestParams {
    Stockfish::Square square;
    std::string expected_string;
};

class SquareToStringConverterTest : public ::testing::TestWithParam<SquareToStringConverterTestParams> {};

TEST_P(SquareToStringConverterTest, Convert) {
    const auto& params = GetParam();
    std::string piece_str = square_to_string_converter::convert(params.square);
    EXPECT_EQ(piece_str, params.expected_string);
}

INSTANTIATE_TEST_SUITE_P(
        SquareToStringConverterTests,
        SquareToStringConverterTest,
        ::testing::Values(
                SquareToStringConverterTestParams{Stockfish::Square::SQ_A1, "a1"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_B1, "b1"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_C1, "c1"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_D1, "d1"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_E1, "e1"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_F1, "f1"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_G1, "g1"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_H1, "h1"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_A2, "a2"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_B2, "b2"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_C2, "c2"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_D2, "d2"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_E2, "e2"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_F2, "f2"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_G2, "g2"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_H2, "h2"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_A3, "a3"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_B3, "b3"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_C3, "c3"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_D3, "d3"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_E3, "e3"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_F3, "f3"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_G3, "g3"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_H3, "h3"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_A4, "a4"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_B4, "b4"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_C4, "c4"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_D4, "d4"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_E4, "e4"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_F4, "f4"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_G4, "g4"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_H4, "h4"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_A5, "a5"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_B5, "b5"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_C5, "c5"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_D5, "d5"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_E5, "e5"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_F5, "f5"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_G5, "g5"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_H5, "h5"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_A6, "a6"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_B6, "b6"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_C6, "c6"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_D6, "d6"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_E6, "e6"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_F6, "f6"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_G6, "g6"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_H6, "h6"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_A7, "a7"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_B7, "b7"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_C7, "c7"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_D7, "d7"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_E7, "e7"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_F7, "f7"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_G7, "g7"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_H7, "h7"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_A8, "a8"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_B8, "b8"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_C8, "c8"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_D8, "d8"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_E8, "e8"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_F8, "f8"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_G8, "g8"},
                SquareToStringConverterTestParams{Stockfish::Square::SQ_H8, "h8"}
        )
);
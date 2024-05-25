#include <gtest/gtest.h>

#include "../include/piece_to_string_converter.h"
#include "../thirdparty/Stockfish/src/types.h"

TEST(piece_to_string_converter_test, Convert) {
    Stockfish::Piece piece = Stockfish::B_BISHOP;

    const std::string piece_str = piece_to_string_converter::convert(piece);

    EXPECT_EQ(piece_str, "b");
}
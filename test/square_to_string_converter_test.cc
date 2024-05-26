#include <gtest/gtest.h>

#include "../include/square_to_string_converter.h"
#include "../thirdparty/Stockfish/src/types.h"

TEST(SquareToStringConverterTest, Convert) {
const std::string piece_str = square_to_string_converter::convert(Stockfish::Square::SQ_E4);

EXPECT_EQ(piece_str, "e4");
}
//
// Created by Akeman on 25-May-24.
//

#ifndef DIGITAL_CHESS_BOARD_PIECE_TO_STRING_CONVERTER_H
#define DIGITAL_CHESS_BOARD_PIECE_TO_STRING_CONVERTER_H

#include "types.h"

class piece_to_string_converter {
public:
    std::string convert(Stockfish::Piece piece);
};


#endif //DIGITAL_CHESS_BOARD_PIECE_TO_STRING_CONVERTER_H

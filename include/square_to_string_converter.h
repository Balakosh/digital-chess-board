//
// Created by Akeman on 26-May-24.
//

#ifndef DIGITAL_CHESS_BOARD_SQUARE_TO_STRING_CONVERTER_H
#define DIGITAL_CHESS_BOARD_SQUARE_TO_STRING_CONVERTER_H

#include "../thirdparty/Stockfish/src/types.h"

class square_to_string_converter {
public:
    static std::string convert(Stockfish::Square square);
};


#endif //DIGITAL_CHESS_BOARD_SQUARE_TO_STRING_CONVERTER_H

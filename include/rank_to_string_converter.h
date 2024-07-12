//
// Created by Akeman on 22-Jun-24.
//

#ifndef DIGITAL_CHESS_BOARD_RANK_TO_STRING_CONVERTER_H
#define DIGITAL_CHESS_BOARD_RANK_TO_STRING_CONVERTER_H

#include "../thirdparty/Stockfish/src/types.h"

class rank_to_string_converter {
public:
    static std::string convert(Stockfish::Rank rank);
};

#endif //DIGITAL_CHESS_BOARD_RANK_TO_STRING_CONVERTER_H

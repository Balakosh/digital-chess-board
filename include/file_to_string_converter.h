//
// Created by Akeman on 09-Jun-24.
//

#ifndef DIGITAL_CHESS_BOARD_FILE_TO_STRING_CONVERTER_H
#define DIGITAL_CHESS_BOARD_FILE_TO_STRING_CONVERTER_H

#include "../thirdparty/Stockfish/src/types.h"

class file_to_string_converter {
public:
    static std::string convert(Stockfish::File file);
};


#endif //DIGITAL_CHESS_BOARD_FILE_TO_STRING_CONVERTER_H

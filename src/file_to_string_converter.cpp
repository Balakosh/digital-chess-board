//
// Created by Akeman on 09-Jun-24.
//

#include "file_to_string_converter.h"

std::string file_to_string_converter::convert(Stockfish::File file) {
    switch (file) {
        case Stockfish::File::FILE_A: return "a";
        case Stockfish::File::FILE_B: return "b";
        case Stockfish::File::FILE_C: return "c";
        case Stockfish::File::FILE_D: return "d";
        case Stockfish::File::FILE_E: return "e";
        case Stockfish::File::FILE_F: return "f";
        case Stockfish::File::FILE_G: return "g";
        case Stockfish::File::FILE_H: return "h";
        default: return "?"; // Return "?" for unknown values
    }
}
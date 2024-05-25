//
// Created by Akeman on 25-May-24.
//

#include "piece_to_string_converter.h"

std::string piece_to_string_converter::convert(Stockfish::Piece piece) {
    switch (piece) {
        case Stockfish::NO_PIECE:
            return "no_piece";
        case Stockfish::W_PAWN:
        case Stockfish::B_PAWN:
            return "";
        case Stockfish::W_KNIGHT:
        case Stockfish::B_KNIGHT:
            return "n";
        case Stockfish::W_BISHOP:
        case Stockfish::B_BISHOP:
            return "b";
        case Stockfish::W_ROOK:
        case Stockfish::B_ROOK:
            return "r";
        case Stockfish::W_QUEEN:
        case Stockfish::B_QUEEN:
            return "q";
        case Stockfish::W_KING:
        case Stockfish::B_KING:
            return "k";
        default:
            return "unknown";
    }
}

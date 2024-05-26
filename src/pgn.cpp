//
// Created by Akeman on 25-May-24.
//

#include <sstream>

#include "pgn.h"
#include "piece_to_string_converter.h"
#include "square_to_string_converter.h"

void pgn::record_move(Stockfish::Square from, Stockfish::Square to, Stockfish::Position& pos) {
    const std::string move_stirng = move_to_string(from, to, pos);
    moves.push_back(move_stirng);
}

std::string pgn::move_to_string(Stockfish::Square from, Stockfish::Square to, Stockfish::Position& pos)
{
    Stockfish::Move move(from, to);
    const bool is_legal_move = pos.legal(move) && pos.pseudo_legal(move);

    if (is_legal_move) {
        Stockfish::Piece piece = pos.piece_on(move.from_sq());
        const std::string piece_str = piece_to_string_converter::convert(piece);
        const std::string square_str = square_to_string_converter::convert(to);

        return piece_str + square_str;
    } else {
        return "illegal move!";
    }
}

std::string pgn::get_pgn() {
    std::ostringstream pgn_string;
    for (size_t i = 0; i < moves.size(); ++i) {
        if (i % 2 == 0) {
            pgn_string << (i / 2 + 1) << ". ";
        }
        pgn_string << moves[i] << " ";
    }
    return pgn_string.str();
}


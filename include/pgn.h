//
// Created by Akeman on 25-May-24.
//

#ifndef DIGITAL_CHESS_BOARD_PGN_H
#define DIGITAL_CHESS_BOARD_PGN_H

#include "../thirdparty/Stockfish/src/position.h"
#include "../thirdparty/Stockfish/src/types.h"

class pgn {
public:
    void record_move(Stockfish::Square from, Stockfish::Square to, Stockfish::Position&);
    std::string get_pgn();
    static std::string move_to_string(Stockfish::Square from, Stockfish::Square to, Stockfish::Position& pos);

    enum castling {
        no_castling,
        short_castling,
        long_castling
    };

private:
    std::vector<std::string> moves;
    static castling is_castling_move(const Stockfish::Piece& piece, const Stockfish::Square& from, const Stockfish::Square& to);
    static bool is_en_passant(Stockfish::Piece& piece, Stockfish::Square& from, Stockfish::Square& to);

    static bool are_files_adjacent(Stockfish::File f1, Stockfish::File f2) {
        return std::abs(f1 - f2) == 1;
    }

    static bool are_ranks_adjacent(Stockfish::Rank r1, Stockfish::Rank r2) {
        return std::abs(r1 - r2) == 1;
    }
};


#endif //DIGITAL_CHESS_BOARD_PGN_H

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
    static pgn::castling is_castling_move(Stockfish::Piece& piece, Stockfish::Square& from, Stockfish::Square& to);
};


#endif //DIGITAL_CHESS_BOARD_PGN_H

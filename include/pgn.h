//
// Created by Akeman on 25-May-24.
//

#ifndef DIGITAL_CHESS_BOARD_PGN_H
#define DIGITAL_CHESS_BOARD_PGN_H

#include "position.h"

class pgn {
public:
    void record_move(Stockfish::Move, Stockfish::Position&);
    std::string get_pgn();

private:
    std::vector<std::string> moves;

    std::string move_to_string(Stockfish::Move, Stockfish::Position&);
};


#endif //DIGITAL_CHESS_BOARD_PGN_H

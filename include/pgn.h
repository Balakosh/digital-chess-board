//
// Created by Akeman on 25-May-24.
//

#ifndef DIGITAL_CHESS_BOARD_PGN_H
#define DIGITAL_CHESS_BOARD_PGN_H

#include "../thirdparty/Stockfish/src/position.h"
#include "../thirdparty/Stockfish/src/types.h"

class pgn {
public:
    void record_move(Stockfish::Square from, Stockfish::Square to, Stockfish::Position&, Stockfish::StateInfo& stateInfo);
    std::string get_pgn();
    static std::string move_to_string(Stockfish::Square from, Stockfish::Square to, Stockfish::Position& pos, Stockfish::StateInfo& stateInfo);

private:
    std::vector<std::string> moves;
    static bool is_castling_move(const Stockfish::Piece& piece, const Stockfish::Square& from, const Stockfish::Square& to);
    static bool is_en_passant(Stockfish::Piece& piece, Stockfish::Square& from, Stockfish::Square& to);
    static bool can_another_piece_reach(const Stockfish::Move& my_move, const Stockfish::Position& pos, Stockfish::PieceType pieceType, Stockfish::Square destSquare);

    static bool are_files_adjacent(Stockfish::File f1, Stockfish::File f2) {
        return std::abs(f1 - f2) == 1;
    }

    static bool are_ranks_adjacent(Stockfish::Rank r1, Stockfish::Rank r2) {
        return std::abs(r1 - r2) == 1;
    }

    static constexpr Stockfish::PieceType type_of(Stockfish::Piece pc) {
        return Stockfish::PieceType((pc - 1) % 8 + 1);
    }
};


#endif //DIGITAL_CHESS_BOARD_PGN_H

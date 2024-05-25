#include <iostream>

#include "position.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Stockfish::Bitboards::init();
    Stockfish::Position::init();
    Stockfish::Position pos;
    Stockfish::Bitboard bitboard;
    Stockfish::StateInfo si;

    // Set up the position using a FEN string
    std::string fenStr = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"; // Starting position
    pos.set(fenStr, false, &si);
    Stockfish::Move move(Stockfish::SQ_E2, Stockfish::SQ_E4);
    const bool is_legal_move = pos.legal(move);
    std::cout << "is_legal_move: " << is_legal_move << std::endl;
    Stockfish::StateInfo newstate;
    pos.do_move(move, newstate);
    bitboard = pos.pieces();
    Stockfish::Piece piece = pos.piece_on(Stockfish::Square::SQ_A1);
    std::cout << "piece: " << piece << std::endl;

    // Call the fen() method and print the FEN string
    std::cout << "FEN: " << pos.fen() << std::endl;
    std::cout << "bitboard: " << Stockfish::Bitboards::pretty(bitboard) << std::endl;

    return 0;
}
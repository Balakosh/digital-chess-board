#include <iostream>

#include "position.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Stockfish::Position pos;
    pos.init();
    auto fen = pos.fen();

    std::cout << fen << std::endl;

    return 0;
}
//
// Created by Akeman on 22-Jun-24.
//

#include "rank_to_string_converter.h"

std::string rank_to_string_converter::convert(Stockfish::Rank rank) {
    switch (rank) {
        case Stockfish::Rank::RANK_1: return "1";
        case Stockfish::Rank::RANK_2: return "2";
        case Stockfish::Rank::RANK_3: return "3";
        case Stockfish::Rank::RANK_4: return "4";
        case Stockfish::Rank::RANK_5: return "5";
        case Stockfish::Rank::RANK_6: return "6";
        case Stockfish::Rank::RANK_7: return "7";
        case Stockfish::Rank::RANK_8: return "8";
        default: return "?"; // Return "?" for unknown values
    }
}

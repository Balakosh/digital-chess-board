//
// Created by Akeman on 25-May-24.
//

#include <sstream>

#include "pgn.h"
#include "piece_to_string_converter.h"
#include "square_to_string_converter.h"
#include "file_to_string_converter.h"
#include "rank_to_string_converter.h"
#include "movegen.h"

void pgn::record_move(Stockfish::Square from, Stockfish::Square to, Stockfish::Position& pos) {
    const std::string move_stirng = move_to_string(from, to, pos);
    moves.push_back(move_stirng);
}

pgn::castling pgn::is_castling_move(const Stockfish::Piece& piece, const Stockfish::Square& from, const Stockfish::Square& to)
{
    if ((piece == Stockfish::W_KING && from == Stockfish::SQ_E1) ||
        (piece == Stockfish::B_KING && from == Stockfish::SQ_E8))
    {
        if (to == Stockfish::SQ_G1 || to == Stockfish::SQ_G8)
        {
            return pgn::short_castling;
        }
        else if (to == Stockfish::SQ_C1 || to == Stockfish::SQ_C8)
        {
            return pgn::long_castling;
        }
    }

    return pgn::no_castling;
}

bool pgn::is_en_passant(Stockfish::Piece& piece, Stockfish::Square& from, Stockfish::Square& to)
{
    if(piece == Stockfish::W_PAWN || piece == Stockfish::B_PAWN)
    {
        const Stockfish::File file_from = Stockfish::file_of(from);
        const Stockfish::File file_to = Stockfish::file_of(to);

        const Stockfish::Rank rank_from = Stockfish::rank_of(from);
        const Stockfish::Rank rank_to = Stockfish::rank_of(to);

        return are_files_adjacent(file_from, file_to) && are_ranks_adjacent(rank_from, rank_to);
    }

    return false;
}

bool pgn::can_another_piece_reach(const Stockfish::Move& my_move,const Stockfish::Position& pos, Stockfish::PieceType pieceType, Stockfish::Square destSquare) {
    Stockfish::ExtMove moveList[256];
    Stockfish::ExtMove* end = generate<Stockfish::LEGAL>(pos, moveList);

    for (Stockfish::ExtMove* move = moveList; move != end; ++move) {
        if (my_move.raw() != move->raw() && Stockfish::type_of(pos.piece_on(move->from_sq())) == pieceType && move->to_sq() == destSquare) {
            return true;
        }
    }

    return false;
}

std::string pgn::move_to_string(Stockfish::Square from, Stockfish::Square to, Stockfish::Position& pos)
{
    // todo check PROMOTION
    // todo check check

    Stockfish::Piece piece = pos.piece_on(from);
    const Stockfish::PieceType piece_type = type_of(piece);
    const pgn::castling castling = is_castling_move(piece, from, to);

    switch (castling) {
        case pgn::castling::short_castling:
            return "O-O";
        case pgn::castling::long_castling:
            return "O-O-O";
        case no_castling:
            break;
    }

    Stockfish::Move move(from, to);
    if (is_en_passant(piece, from, to))
    {
        move = Stockfish::Move::make<Stockfish::MoveType::EN_PASSANT>(from, to);
    }

    const bool is_legal_move = pos.legal(move) && pos.pseudo_legal(move);

    if (is_legal_move) {
        const bool is_capture = pos.capture(move);
        const std::string piece_str = piece_to_string_converter::convert(piece);
        const std::string square_str = square_to_string_converter::convert(to);
        std::string capture_str = is_capture ? "x" : "";

        if (can_another_piece_reach(move, pos, piece_type, to))
        {
            if (Stockfish::rank_of(from) == Stockfish::rank_of(to))
            {
                const Stockfish::File file_from = Stockfish::file_of(from);
                capture_str.insert(0, file_to_string_converter::convert(file_from));
            }
            else if (Stockfish::file_of(from) == Stockfish::file_of(to))
            {
                const Stockfish::Rank rank_from = Stockfish::rank_of(from);
                capture_str.insert(0, rank_to_string_converter::convert(rank_from));
            } else
            {
                const Stockfish::File file_from = Stockfish::file_of(from);
                capture_str.insert(0, file_to_string_converter::convert(file_from));
            }
        }

        if (is_capture && ((piece == Stockfish::W_PAWN) || (piece == Stockfish::B_PAWN)))
        {
            const Stockfish::File file_from = Stockfish::file_of(from);
            capture_str.insert(0, file_to_string_converter::convert(file_from));
        }

        return piece_str + capture_str + square_str;
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


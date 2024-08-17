//
// Created by Akeman on 16-Aug-24.
//

#ifndef DIGITAL_CHESS_BOARD_LICHESS_H
#define DIGITAL_CHESS_BOARD_LICHESS_H


class lichess {
public:
    static void pgn_upload(std::string pgn);
private:
    static std::string get_token();
};


#endif //DIGITAL_CHESS_BOARD_LICHESS_H

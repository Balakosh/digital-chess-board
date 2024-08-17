#include <gtest/gtest.h>

#include "../include/lichess.h"

class LichessTest : public ::testing::Test {
protected:

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(LichessTest, UploadPGN) {
    std::string pgn = R"(
    [Event "Live Chess"]
    [Site "Lichess"]
    [Date "2023.08.16"]
    [Round "-"]
    [White "Player1"]
    [Black "Player2"]
    [Result "1-0"]
    1. e4 e5 2. Nf3 Nc6 3. Bb5 a6 4. Ba4 Nf6 5. O-O Be7 6. Re1 b5 7. Bb3 d6 8. c3 O-O 9. h3
    )";

    lichess::pgn_upload(pgn);
}
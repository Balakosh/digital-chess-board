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

    lichess::pgn_upload();
}
#include <gtest/gtest.h>
#include <ApprovalTests.hpp>


using namespace ApprovalTests;

extern "C" {
#include "game_runner.h"
}

TEST(GameTest, itsLockedDown) {
    testing::internal::CaptureStdout();
    playGame();
    const std::string &out = testing::internal::GetCapturedStdout();
    ApprovalTests::Approvals::verify(out);
}

TEST(GameTest, should_give_coin_to_right_player) {
    Game *game = newGame();
    add(game, "Chet");
    add(game, "Sue");

    canAnswerQuestion(game, 1);
    wrongAnswer(game);

    canAnswerQuestion(game, 1);
    wasCorrectlyAnswered(game);

    canAnswerQuestion(game, 1);
    wasCorrectlyAnswered(game);

    ASSERT_EQ(game->players->players[0]->purses, 1);
    ASSERT_EQ(game->players->players[1]->purses, 1);
}

TEST(GameTest, should_finish_game_when_has_a_winner) {
    Game *game = newGame();
    add(game, "Chet");
    add(game, "Sue");

    game->players->players[0]->purses = 5;

    canAnswerQuestion(game, 1);
    wrongAnswer(game);

    canAnswerQuestion(game, 1);
    wasCorrectlyAnswered(game);

    canAnswerQuestion(game, 1);
    int notWinner = wasCorrectlyAnswered(game);

    ASSERT_EQ(notWinner, 0);
}
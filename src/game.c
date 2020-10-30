#include <stdio.h>
#include <string.h>
#include "game.h"
#include "question_category.h"

void movePlayerAndAskQuestion(Game *pGame, int roll);

const char *currentCategory(Game *pGame);

void askQuestion(Game *pGame);

const char *getCurrentPlayerName(const Game *game);

void moveToNextPlayer(Game *game);

Game *newGame() {
    Game *game = (Game *) malloc(sizeof(Game));

    game->playerCount = 0;

    game->currentPlayer = 0;

    for (int i = 0; i < 4; ++i) {
        game->questionCategory[i] = newQuestionCategory(CATEGORIES[i]);
        initQuestions(game->questionCategory[i], MAX_QUESTIONS_COUNT);
    }
    return game;
}

int add(Game *game, const char *playerName) {
    game->players[game->playerCount] = newPlayer(playerName);
    game->playerCount++;

    printf("%s was added\r\n", playerName);
    printf("They are player number %d\r\n", game->playerCount);
    return 1;
}

void roll(Game *game, int roll) {
    printf("%s is the current player\r\n", getCurrentPlayerName(game));
    printf("They have rolled a %d\r\n", roll);

    if (game->players[game->currentPlayer]->inPenaltyBox) {
        if (roll % 2 != 0) {
            game->isGettingOutOfPenaltyBox = 1;

            printf("%s is getting out of the penalty box\r\n", getCurrentPlayerName(game));
            movePlayerAndAskQuestion(game, roll);
        } else {
            printf("%s is not getting out of the penalty box\r\n", getCurrentPlayerName(game));
            game->isGettingOutOfPenaltyBox = 0;
        }
    } else {
        movePlayerAndAskQuestion(game, roll);
    }
}

const char *getCurrentPlayerName(const Game *game) { return game->players[game->currentPlayer]->name; }

void movePlayerAndAskQuestion(Game *pGame, int roll) {
    moveSteps(pGame->players[pGame->currentPlayer], roll);

    printf("%s's new location is %d\r\n", getCurrentPlayerName(pGame),
           pGame->players[pGame->currentPlayer]->place);
    printf("The category is %s\r\n", currentCategory(pGame));
    askQuestion(pGame);
}

void askQuestion(Game *pGame) {
    for (int i = 0; i < CATEGORY_COUNT; ++i) {
        if (strcmp(currentCategory(pGame), CATEGORIES[i]) == 0)
            printf("%s\r\n", pickOneQuestion(pGame->questionCategory[i]));
    }
}

const char *currentCategory(Game *pGame) {
    if (pGame->players[pGame->currentPlayer]->place == 0) return "Pop";
    if (pGame->players[pGame->currentPlayer]->place == 4) return "Pop";
    if (pGame->players[pGame->currentPlayer]->place == 8) return "Pop";
    if (pGame->players[pGame->currentPlayer]->place == 1) return "Science";
    if (pGame->players[pGame->currentPlayer]->place == 5) return "Science";
    if (pGame->players[pGame->currentPlayer]->place == 9) return "Science";
    if (pGame->players[pGame->currentPlayer]->place == 2) return "Sports";
    if (pGame->players[pGame->currentPlayer]->place == MAX_PLAYERS_COUNT) return "Sports";
    if (pGame->players[pGame->currentPlayer]->place == 10) return "Sports";
    return "Rock";
}

int wrongAnswer(Game *game) {
    printf("Question was incorrectly answered\r\n");
    printf("%s was sent to the penalty box\r\n", getCurrentPlayerName(game));
    putIntoPenaltyBox(game->players[game->currentPlayer]);

    moveToNextPlayer(game);
    return 1;
}

void moveToNextPlayer(Game *game) {
    game->currentPlayer++;
    if (game->currentPlayer == game->playerCount) game->currentPlayer = 0;
}

int wasCorrectlyAnswered(Game *game) {
    if (game->players[game->currentPlayer]->inPenaltyBox) {
        if (game->isGettingOutOfPenaltyBox) {
            printf("Answer was correct!!!!\r\n");
            gotOneGoldCoin(game->players[game->currentPlayer]);
            printf("%s now has %d Gold Coins.\r\n", getCurrentPlayerName(game), game->players[game->currentPlayer]->purses);

            int notWinner = !isWinner(game->players[game->currentPlayer]);

            moveToNextPlayer(game);

            return notWinner;
        } else {
            moveToNextPlayer(game);
            return 1;
        }
    } else {
        printf("Answer was correct!!!!\r\n");
        gotOneGoldCoin(game->players[game->currentPlayer]);
        printf("%s now has %d Gold Coins.\r\n", getCurrentPlayerName(game), game->players[game->currentPlayer]->purses);

        int winner = !isWinner(game->players[game->currentPlayer]);
        moveToNextPlayer(game);
        return winner;
    }
}


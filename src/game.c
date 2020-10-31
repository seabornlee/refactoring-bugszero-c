#include <stdio.h>
#include <string.h>
#include "game.h"
#include "question_category.h"

void movePlayerAndAskQuestion(Game *pGame, int roll);

const char *currentCategory(Game *pGame);

void askQuestion(Game *pGame);

const char *getCurrentPlayerName(const Game *game);

Game *newGame() {
    Game *game = (Game *) malloc(sizeof(Game));

    game->players = newPlayers();

    for (int i = 0; i < CATEGORY_COUNT; ++i) {
        game->questionCategory[i] = newQuestionCategory(CATEGORIES[i]);
        initQuestions(game->questionCategory[i], MAX_QUESTIONS_COUNT);
    }
    return game;
}

int add(Game *game, const char *playerName) {
    addPlayer(game->players, playerName);

    printf("%s was added\r\n", playerName);
    printf("They are player number %d\r\n", game->players->playerCount);
    return 1;
}

int canAnswerQuestion(Game *game, int roll) {
    printf("%s is the current player\r\n", getCurrentPlayerName(game));
    printf("They have rolled a %d\r\n", roll);

    if (getCurrentPlayer(game->players)->inPenaltyBox) {
        if (roll % 2 != 0) {
            releasePlayerFromPenaltyBox(getCurrentPlayer(game->players));
            printf("%s is getting out of the penalty box\r\n", getCurrentPlayerName(game));
            movePlayerAndAskQuestion(game, roll);
            return 1;
        } else {
            printf("%s is not getting out of the penalty box\r\n", getCurrentPlayerName(game));
            moveToNext(game->players);
            return 0;
        }
    } else {
        movePlayerAndAskQuestion(game, roll);
        return 1;
    }
}

const char *getCurrentPlayerName(const Game *game) { return getCurrentPlayer(game->players)->name; }

void movePlayerAndAskQuestion(Game *pGame, int roll) {
    moveSteps(getCurrentPlayer(pGame->players), roll);

    printf("%s's new location is %d\r\n", getCurrentPlayerName(pGame),
           getCurrentPlayer(pGame->players)->place);
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
    return CATEGORIES[getCurrentPlayer(pGame->players)->place % CATEGORY_COUNT];
}

int wrongAnswer(Game *game) {
    printf("Question was incorrectly answered\r\n");
    printf("%s was sent to the penalty box\r\n", getCurrentPlayerName(game));
    putIntoPenaltyBox(getCurrentPlayer(game->players));

    moveToNext(game->players);
    return 1;
}

int wasCorrectlyAnswered(Game *game) {
    printf("Answer was correct!!!!\r\n");
    gotOneGoldCoin(getCurrentPlayer(game->players));
    printf("%s now has %d Gold Coins.\r\n", getCurrentPlayerName(game), getCurrentPlayer(game->players)->purses);

    int notWinner = !isWinner(getCurrentPlayer(game->players));
    moveToNext(game->players);
    return notWinner;
}


#include <stdio.h>
#include <string.h>
#include "game.h"
#include "question_category.h"

void movePlayerAndAskQuestion(Game *pGame, int roll);

Game *newGame() {
    Game *game = (Game *) malloc(sizeof(Game));
    game->players = newPlayers();
    game->questionMap = newQuestionMap();
    return game;
}

int add(Game *game, const char *playerName) {
    addPlayer(game->players, playerName);

    printf("%s was added\r\n", playerName);
    printf("They are player number %d\r\n", game->players->playerCount);
    return 1;
}

int canAnswerQuestion(Game *game, int roll) {
    printf("%s is the current player\r\n", getCurrentPlayer(game->players)->name);
    printf("They have rolled a %d\r\n", roll);

    if (getCurrentPlayer(game->players)->inPenaltyBox) {
        if (roll % 2 != 0) {
            releasePlayerFromPenaltyBox(getCurrentPlayer(game->players));
            printf("%s is getting out of the penalty box\r\n", getCurrentPlayer(game->players)->name);
            movePlayerAndAskQuestion(game, roll);
            return 1;
        } else {
            printf("%s is not getting out of the penalty box\r\n", getCurrentPlayer(game->players)->name);
            moveToNext(game->players);
            return 0;
        }
    } else {
        movePlayerAndAskQuestion(game, roll);
        return 1;
    }
}

void movePlayerAndAskQuestion(Game *pGame, int roll) {
    moveSteps(getCurrentPlayer(pGame->players), roll);

    printf("%s's new location is %d\r\n", getCurrentPlayer(pGame->players)->name,
           getCurrentPlayer(pGame->players)->place);
    int place = getCurrentPlayer(pGame->players)->place;
    printf("The category is %s\r\n", CATEGORIES[place % CATEGORY_COUNT]);
    askOneQuestion(pGame->questionMap, place);
}

int wrongAnswer(Game *game) {
    printf("Question was incorrectly answered\r\n");
    printf("%s was sent to the penalty box\r\n", getCurrentPlayer(game->players)->name);
    putIntoPenaltyBox(getCurrentPlayer(game->players));

    moveToNext(game->players);
    return 1;
}

int wasCorrectlyAnswered(Game *game) {
    printf("Answer was correct!!!!\r\n");
    gotOneGoldCoin(getCurrentPlayer(game->players));
    printf("%s now has %d Gold Coins.\r\n", getCurrentPlayer(game->players)->name, getCurrentPlayer(game->players)->purses);

    int notWinner = !isWinner(getCurrentPlayer(game->players));
    moveToNext(game->players);
    return notWinner;
}


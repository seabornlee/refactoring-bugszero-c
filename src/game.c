#include <stdio.h>
#include "game.h"

int howManyPlayers(Game *pGame);

void movePlayerAndAskQuestion(Game *pGame, int roll);

const char *currentCategory(Game *pGame);

void askQuestion(Game *pGame);

int didPlayerWin(Game *pGame);

Game *newGame() {
    Game *game = (Game *) malloc(sizeof(Game));

    game->players = newArrayList();
    game->popQuestions = newLinkedList();
    game->scienceQuestions = newLinkedList();
    game->sportsQuestions = newLinkedList();
    game->rockQuestions = newLinkedList();

    for (int i = 0; i < 50; ++i) {
        char str[20] = {0};
        sprintf(str, "%s %d", "Pop Question", i);
        addLast(game->popQuestions, str);

        char str1[20] = {0};
        sprintf(str1, "%s %d", "Science Question", i);
        addLast(game->scienceQuestions, str1);

        char str2[20] = {0};
        sprintf(str2, "%s %d", "Sports Question", i);
        addLast(game->sportsQuestions, str2);

        char str3[25] = {0};
        sprintf(str3, "%s %d", "Rock Question", i);
        addLast(game->rockQuestions, str3);
    }
    return game;
}

int add(Game *game, const char *playerName) {
    addElement(game->players, playerName);
    game->places[howManyPlayers(game)] = 0;
    game->purses[howManyPlayers(game)] = 0;
    game->inPenaltyBox[howManyPlayers(game)] = 0;

    printf("%s was added\r\n", playerName);
    printf("They are player number %d\r\n", size(game->players));
    return 1;
}

int howManyPlayers(Game *pGame) {
    return size(pGame->players);
}

void roll(Game *game, int roll) {
    printf("%s is the current player\r\n", get(game->players, game->currentPlayer));
    printf("They have rolled a %d\r\n", roll);

    if (game->inPenaltyBox[game->currentPlayer]) {
        if (roll % 2 != 0) {
            game->isGettingOutOfPenaltyBox = 1;

            printf("%s is getting out of the penalty box\r\n", get(game->players, game->currentPlayer));
            movePlayerAndAskQuestion(game, roll);
        } else {
            printf("%s is not getting out of the penalty box\r\n", get(game->players, game->currentPlayer));
            game->isGettingOutOfPenaltyBox = 0;
        }
    } else {
        movePlayerAndAskQuestion(game, roll);
    }
}

void movePlayerAndAskQuestion(Game *pGame, int roll) {
    pGame->places[pGame->currentPlayer] = pGame->places[pGame->currentPlayer] + roll;
    if (pGame->places[pGame->currentPlayer] > 11)
        pGame->places[pGame->currentPlayer] = pGame->places[pGame->currentPlayer] - 12;

    printf("%s's new location is %d\r\n", get(pGame->players, pGame->currentPlayer),
           pGame->places[pGame->currentPlayer]);
    printf("The category is %s\r\n", currentCategory(pGame));
    askQuestion(pGame);
}

void askQuestion(Game *pGame) {
    if (currentCategory(pGame) == "Pop")
        printf("%s\r\n", removeFirst(pGame->popQuestions));
    if (currentCategory(pGame) == "Science")
        printf("%s\r\n", removeFirst(pGame->scienceQuestions));
    if (currentCategory(pGame) == "Sports")
        printf("%s\r\n", removeFirst(pGame->sportsQuestions));
    if (currentCategory(pGame) == "Rock")
        printf("%s\r\n", removeFirst(pGame->rockQuestions));
}

const char *currentCategory(Game *pGame) {
    if (pGame->places[pGame->currentPlayer] == 0) return "Pop";
    if (pGame->places[pGame->currentPlayer] == 4) return "Pop";
    if (pGame->places[pGame->currentPlayer] == 8) return "Pop";
    if (pGame->places[pGame->currentPlayer] == 1) return "Science";
    if (pGame->places[pGame->currentPlayer] == 5) return "Science";
    if (pGame->places[pGame->currentPlayer] == 9) return "Science";
    if (pGame->places[pGame->currentPlayer] == 2) return "Sports";
    if (pGame->places[pGame->currentPlayer] == 6) return "Sports";
    if (pGame->places[pGame->currentPlayer] == 10) return "Sports";
    return "Rock";
}

int wrongAnswer(Game *game) {
    printf("Question was incorrectly answered\r\n");
    printf("%s was sent to the penalty box\r\n", get(game->players, game->currentPlayer));
    game->inPenaltyBox[game->currentPlayer] = 1;

    game->currentPlayer++;
    if (game->currentPlayer == game->players->size) game->currentPlayer = 0;
    return 1;
}

int wasCorrectlyAnswered(Game *game) {
    if (game->inPenaltyBox[game->currentPlayer]) {
        if (game->isGettingOutOfPenaltyBox) {
            printf("Answer was correct!!!!\r\n");
            game->currentPlayer++;
            if (game->currentPlayer == game->players->size) game->currentPlayer = 0;
            game->purses[game->currentPlayer]++;
            printf("%s now has %d Gold Coins.\r\n", get(game->players, game->currentPlayer), game->purses[game->currentPlayer]);
            int winner = didPlayerWin(game);

            return winner;
        } else {
            game->currentPlayer++;
            if (game->currentPlayer == game->players->size) game->currentPlayer = 0;
            return 1;
        }
    } else {
        printf("Answer was corrent!!!!\r\n");
        game->purses[game->currentPlayer]++;
        printf("%s now has %d Gold Coins.\r\n", get(game->players, game->currentPlayer), game->purses[game->currentPlayer]);

        int winner = didPlayerWin(game);
        game->currentPlayer++;
        if (game->currentPlayer == game->players->size) game->currentPlayer = 0;

        return winner;
    }
}

int didPlayerWin(Game *pGame) {
    return !(pGame->purses[pGame->currentPlayer] == 6);
}


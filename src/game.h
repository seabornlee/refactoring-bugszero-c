#ifndef REFACTOR_LENGTH_C_GAME_H
#define REFACTOR_LENGTH_C_GAME_H

#include "linked_list.h"
#include "array_list.h"

static const int MAX_PLAYERS_COUNT = 6;

typedef struct _game {
    ArrayList *players;
    int places[MAX_PLAYERS_COUNT];
    int purses[MAX_PLAYERS_COUNT];
    int inPenaltyBox[MAX_PLAYERS_COUNT];

    LinkedList *popQuestions;
    LinkedList *scienceQuestions;
    LinkedList *sportsQuestions;
    LinkedList *rockQuestions;
    int currentPlayer;
    int isGettingOutOfPenaltyBox;
} Game;

Game *newGame();

int add(Game *game, const char *playerName);

void roll(Game *game, int roll);

int wrongAnswer(Game *game);

int wasCorrectlyAnswered(Game *game);

#endif //REFACTOR_LENGTH_C_GAME_H

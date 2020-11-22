#ifndef REFACTOR_LENGTH_C_GAME_H
#define REFACTOR_LENGTH_C_GAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include "linked_list.h"
#include "array_list.h"

typedef struct _game {
    ArrayList *players;
    int places[6];
    int purses[6];
    int inPenaltyBox[6];

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

#ifdef __cplusplus
};
#endif
#endif //REFACTOR_LENGTH_C_GAME_H

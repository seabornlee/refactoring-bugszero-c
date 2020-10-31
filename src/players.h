#ifndef REFACTOR_BUGSZERO_C_PLAYERS_H
#define REFACTOR_BUGSZERO_C_PLAYERS_H

#include "player.h"
#include "linked_list.h"
#include "array_list.h"
#include "question_category.h"

static const int MAX_PLAYERS_COUNT = 6;

typedef struct _players {
    int playerCount;
    int currentPlayer;
    Player *players[MAX_PLAYERS_COUNT];
} Players;

Players *newPlayers();

void addPlayer(Players *players, const char *name);
Player *getCurrentPlayer(Players *players);
void moveToNext(Players *players);
#endif //REFACTOR_BUGSZERO_C_PLAYERS_H

#include "question_category.h"
#include "game.h"
#include <string.h>
#include <stdio.h>
#include "players.h"

Players *newPlayers() {
    Players *players = (Players *) malloc(sizeof(Players));
    players->currentPlayer = 0;
    players->playerCount = 0;
    return players;
}

void addPlayer(Players *players, const char *name) {
    players->players[players->playerCount] = newPlayer(name);
    players->playerCount++;
}

Player *getCurrentPlayer(Players *players) {
    return players->players[players->currentPlayer];
}

void moveToNext(Players *players) {
    players->currentPlayer = (players->currentPlayer + 1) % players->playerCount;
}

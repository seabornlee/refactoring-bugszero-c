#include "player.h"

Player *newPlayer(const char *name) {
    Player *pPlayer = (Player *) malloc(sizeof(Player));
    pPlayer->name = name;
    pPlayer->place = 0;
    pPlayer->inPenaltyBox = 0;
    return pPlayer;
}

void moveSteps(Player *player, int steps) {
    player->place = player->place + steps;
    if (player->place > 11)
        player->place = player->place - 12;
}

void putIntoPenaltyBox(Player *player) {
    player->inPenaltyBox = 1;
}

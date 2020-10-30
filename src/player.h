#ifndef REFACTOR_BUGSZERO_C_PLAYER_H
#define REFACTOR_BUGSZERO_C_PLAYER_H

typedef struct _player {
    const char *name;
    int place;
    int inPenaltyBox;
    int purses;
} Player;

Player *newPlayer(const char *name);

void moveSteps(Player *player, int steps);

void putIntoPenaltyBox(Player *player);

void gotOneGoldCoin(Player *player);

int isWinner(Player *player);

#endif //REFACTOR_BUGSZERO_C_PLAYER_H

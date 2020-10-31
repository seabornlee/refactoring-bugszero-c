#ifndef REFACTOR_LENGTH_C_GAME_H
#define REFACTOR_LENGTH_C_GAME_H

#include "players.h"
#include "question_map.h"

typedef struct _game {
    Players *players;
    QuestionMap *questionMap;
} Game;

Game *newGame();

int add(Game *game, const char *playerName);

int canAnswerQuestion(Game *game, int roll);

int wrongAnswer(Game *game);

int wasCorrectlyAnswered(Game *game);

#endif //REFACTOR_LENGTH_C_GAME_H

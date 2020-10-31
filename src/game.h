#ifndef REFACTOR_LENGTH_C_GAME_H
#define REFACTOR_LENGTH_C_GAME_H

#include "linked_list.h"
#include "array_list.h"
#include "question_category.h"
#include "player.h"

static const int MAX_PLAYERS_COUNT = 6;
static const int MAX_QUESTIONS_COUNT = 50;
static const int CATEGORY_COUNT = 4;
static const char *CATEGORIES[] = {"Pop", "Science", "Sports", "Rock"};

typedef struct _game {
    int playerCount;
    Player *players[MAX_PLAYERS_COUNT];

    QuestionCategory *questionCategory[CATEGORY_COUNT];
    int currentPlayer;
} Game;

Game *newGame();

int add(Game *game, const char *playerName);

int canAnswerQuestion(Game *game, int roll);

int wrongAnswer(Game *game);

int wasCorrectlyAnswered(Game *game);

#endif //REFACTOR_LENGTH_C_GAME_H

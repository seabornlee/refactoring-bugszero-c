#ifndef REFACTOR_BUGSZERO_C_QUESTION_MAP_H
#define REFACTOR_BUGSZERO_C_QUESTION_MAP_H

#include "question_category.h"

static const char *CATEGORIES[] = {"Pop", "Science", "Sports", "Rock", "Blues", "History"};
static const int CATEGORY_COUNT = sizeof(CATEGORIES) / sizeof(CATEGORIES[0]);
static const int MAX_QUESTIONS_COUNT = 50;

typedef struct _question_map {
    QuestionCategory *questionCategory[CATEGORY_COUNT];
} QuestionMap;

QuestionMap *newQuestionMap();

void askOneQuestion(QuestionMap *questionMap, int place);

#endif //REFACTOR_BUGSZERO_C_QUESTION_MAP_H

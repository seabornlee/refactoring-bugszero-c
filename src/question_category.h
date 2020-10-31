#ifndef REFACTOR_BUGSZERO_C_QUESTION_CATEGORY_H
#define REFACTOR_BUGSZERO_C_QUESTION_CATEGORY_H

#include "linked_list.h"

typedef struct _question_category {
    const char *name;
    LinkedList *questions;
} QuestionCategory;

QuestionCategory *newQuestionCategory(const char *category);

void initQuestions(QuestionCategory *pQuestionCategory, int count);

const char *pickOneQuestion(QuestionCategory *pQuestionCategory);

char *createQuestion(int i, const char *category);

#endif //REFACTOR_BUGSZERO_C_QUESTION_CATEGORY_H

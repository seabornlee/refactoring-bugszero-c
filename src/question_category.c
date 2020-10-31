#include "game.h"
#include <string.h>
#include <stdio.h>
#include "question_category.h"

QuestionCategory *newQuestionCategory(const char *category) {
    QuestionCategory *pQuestionCategory = (QuestionCategory *) malloc(sizeof(QuestionCategory));
    pQuestionCategory->name = category;
    pQuestionCategory->questions = newLinkedList();
    return pQuestionCategory;
}

void initQuestions(QuestionCategory *pQuestionCategory, int count) {
    for (int i = 0; i < count; ++i) {
        addLast(pQuestionCategory->questions, createQuestion(i, pQuestionCategory->name));
    }
}

char *createQuestion(int i, const char *category) {
    static char str[25] = {0};
    sprintf(str, "%s Question %d", category, i);
    return str;
}

const char *pickOneQuestion(QuestionCategory *pQuestionCategory) { return removeFirst(pQuestionCategory->questions); }
#include <string.h>
#include "question_map.h"
#include "question_category.h"

void generate(QuestionCategory *pQuestionCategory, int count) {
    for (int i = 0; i < count; ++i) {
        addLast(pQuestionCategory->questions, createQuestion(i, pQuestionCategory->name));
    }
}

QuestionMap *newQuestionMap() {
    QuestionMap *pQuestionMap = (QuestionMap *) malloc(sizeof(QuestionMap));
    for (int i = 0; i < CATEGORY_COUNT; ++i) {
        pQuestionMap->questionCategory[i] = newQuestionCategory(CATEGORIES[i]);
        generate(pQuestionMap->questionCategory[i], MAX_QUESTIONS_COUNT);
    }
    return pQuestionMap;
}

void askOneQuestion(QuestionMap *questionMap, int place) {
    for (int i = 0; i < CATEGORY_COUNT; ++i) {
        if (strcmp(CATEGORIES[place % CATEGORY_COUNT], CATEGORIES[i]) == 0)
            printf("%s\r\n", pickOneQuestion(questionMap->questionCategory[i]));
    }
}

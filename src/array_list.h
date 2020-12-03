#ifndef REFACTOR_BUGSZERO_C_ARRAY_LIST_H
#define REFACTOR_BUGSZERO_C_ARRAY_LIST_H

typedef struct ArrayList {
    const char *elements[100];
    int size;
} ArrayList;

ArrayList *newArrayList();

int addElement(ArrayList *list, const char *element);

int size(ArrayList *list);

const char* get(ArrayList *list, int i);

void destroyArrayList(ArrayList *list);

#endif //REFACTOR_BUGSZERO_C_ARRAY_LIST_H

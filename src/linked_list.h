#ifndef REFACTOR_BUGSZERO_C_LINKED_LIST_H
#define REFACTOR_BUGSZERO_C_LINKED_LIST_H

typedef struct LinkedList {
    const char *element;
    struct LinkedList *next;
} LinkedList;

LinkedList *newLinkedList();

void addLast(LinkedList *linkedList, const char *element);

int len(LinkedList *linkedList);

const char *removeFirst(LinkedList *linkedList);

#endif //REFACTOR_BUGSZERO_C_LINKED_LIST_H
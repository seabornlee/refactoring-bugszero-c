#include <string.h>
#include "array_list.h"

ArrayList *newArrayList() {
    ArrayList *pList = (ArrayList *) malloc(sizeof(ArrayList));
    if (pList == NULL) {
        return pList;
    }

    pList->size = 0;
    return pList;
}

int addElement(ArrayList *list, const char *element) {
    char *newElement = (char *) malloc(strlen(element) + 1);
    if (newElement == NULL) {
        return 0;
    }

    strcpy(newElement, element);
    list->elements[list->size++] = newElement;
    return 1;
}

int size(ArrayList *list) {
    return list->size;
}

const char *get(ArrayList *list, int i) {
    return list->elements[i];
}

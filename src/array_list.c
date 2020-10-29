#include <string.h>
#include "array_list.h"

ArrayList *newArrayList() {
    return (ArrayList *) malloc(sizeof(ArrayList));
}

int addElement(ArrayList *list, const char *element) {
    list->elements[list->size] = malloc(strlen(element) + 1);
    strcpy(list->elements[list->size], element);
    list->size++;
    return 1;
}

int size(ArrayList *list) {
    return list->size;
}

const char *get(ArrayList *list, int i) {
    return list->elements[i];
}

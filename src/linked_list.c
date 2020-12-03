#include <string.h>
#include "linked_list.h"
#include "stdlib.h"
#include <stdio.h>

LinkedList *newLinkedList() {
    LinkedList *head = (LinkedList *) malloc(sizeof(LinkedList));

    if (head == NULL) {
        printf("空间缓存不足");
        return head;
    }

    head->element = "";
    head->next = NULL;
    return head;
}

void addLast(LinkedList *linkedList, const char *element) {
    LinkedList *node = (LinkedList *) malloc(sizeof(LinkedList));

    node->element = malloc(strlen(element) + 1);
    strcpy(node->element, element);
    node->next = NULL;

    LinkedList *currentNode = linkedList;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = node;
}

int len(LinkedList *linkedList) {
    int len = 0;
    LinkedList *currentNode = linkedList->next;
    while (currentNode != NULL) {
        len++;
        currentNode = currentNode->next;
    }
    return len;
}

const char *removeFirst(LinkedList *linkedList) {
    const char *element = linkedList->next->element;
    linkedList->next = linkedList->next->next;
    return element;
}

void destroyLinkedList(LinkedList *linkedList) {
    LinkedList *current;
    while (linkedList->next) {
        current = linkedList->next;
        linkedList->next = current->next;
        free(current);
    }
    free(linkedList);
}

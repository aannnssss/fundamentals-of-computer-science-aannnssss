#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct list {
    int size;
    Node* head;
} List;

typedef struct listIterator {
    Node *node;
    List *list;
} ListIterator;

List* listCreate();

Node* nodeCreate(int data);

void listPushFront(List* list, int data);

void listPushBack(List* list, int data);

bool listIsEmpty(List *list);

void listPopFront(List* list);

void listPopBack(List* list);

int listSize(List* list);

ListIterator listIteratorBegin(const List * const list);

ListIterator listIteratorEnd(const List * const list);

ListIterator *listIteratorNext(ListIterator * const it);

void listPrint(List *list);

void nodeInsert(List *list, int index, int value);

void nodeDelete(List *list, int index);

Node* nodeGet(List* list, int index);

void Swap(List *list, int k);

#endif // LIST_H

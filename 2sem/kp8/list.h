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

bool nodeCreate(int data, Node** node);

bool listPushFront(List* list, int data);

bool listPushBack(List* list, int data);

bool listIsEmpty(List *list);

bool listPopFront(List* list);

bool listPopBack(List* list);

ptrdiff_t listSize(List* list);

ListIterator listIteratorBegin(const List * const list);

ListIterator listIteratorEnd(const List * const list);

ListIterator *listIteratorNext(ListIterator * const it);

bool listPrint(List *list);

bool nodeInsert(List *list, int index, int value);

bool nodeDelete(List *list, int index);

bool nodeGet(Node** node, List* list, int index);

void Swap(List *list, int k);

#endif // LIST_H

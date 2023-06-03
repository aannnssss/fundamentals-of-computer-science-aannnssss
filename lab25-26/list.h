#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Node Node;

typedef struct {
    Node *data;
    ptrdiff_t head, tail;
    size_t size;
} List;

typedef struct {
    List *list;
    ptrdiff_t index;
} ListIterator;

bool listCreate(List *list);

void listClear(List *list);

void listDestroy(List *list);

bool listFront(const List *list, int *ptr);

bool listBack(const List *list, int *ptr);

bool listPushFront(List *list, int value);

bool listPushBack(List *list, int value);

bool listPopFront(List *list);

bool listPopBack(List *list);

bool listErase(List *list, int value);

bool listIsEmpty(const List * list);

bool listIsFull(const List * list);

size_t listSize(const List *list);

void listPrint(const List *list);

void listDebugPrint(const List *list);

ListIterator listIteratorBegin(List *list);

ListIterator listIteratorEnd(List *list);

bool listIteratorGet(const ListIterator *iterator, int *ptr);

bool listIteratorSet(ListIterator *iterator, int value);

// iterator invalidates if list is changed
bool listIteratorInsert(ListIterator *iterator, int value); // before

// iterator invalidates if list is changed
bool listIteratorErase(ListIterator *iterator); // iterator becomes next

bool listIteratorNext(ListIterator *iterator);

bool listIteratorPrev(ListIterator *iterator);

#endif // LIST_H

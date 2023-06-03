#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX_SIZE (100U)

typedef struct {
    int value;
    ptrdiff_t prev;
    ptrdiff_t next;
} Node;

typedef struct {
    ptrdiff_t head;
    ptrdiff_t tail;
    size_t size;
    Node *data;
} List;


bool create(List* const list);

bool pushFront(List * const list, int value);

bool pushBack(List * const list, int value);

bool popFront(List * const list);

bool popBack(List * const list);

bool isEmpty(const List * const list);

void printList(const List * const list);

void printDebugList(const List * const list);

size_t listSize(const List * const list) ;

void clear(List * const list);

void destroy(List * const list);

void unlink(List* const list, const size_t index);

void swapLast(List * const list, const size_t index);

bool erase(List * const list, int value);

#endif // LIST_H

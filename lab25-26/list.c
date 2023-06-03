#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define MAX_SIZE (100U)

struct Node {
    ptrdiff_t prev, next;
    int value;
};

static void listUnlink(List *list, size_t index);

bool listCreate(List * const list) {
    Node * const ptr = malloc(MAX_SIZE * sizeof(Node));
    if (ptr == NULL)
        return false;
    list->data = ptr;
    list->head = list->tail = -1;
    list->size = 0;
    return true;
}

void listClear(List * const list) {
    list->head = list->tail = -1;
    list->size = 0;
}

void listDestroy(List * const list) {
    free(list->data);
}


bool listFront(const List * const list, int * const ptr) {
    if (listIsEmpty(list))
        return false;
    *ptr = list->data[list->head].value;
    return true;
}

bool listBack(const List * const list, int * const ptr) {
    if (listIsEmpty(list))
        return false;
    *ptr = list->data[list->tail].value;
    return true;
}

bool listPushFront(List * const list, const int value) {
    if (listIsFull(list))
        return false;
    const ptrdiff_t index = list->size;
    list->data[index] = (Node) {
        .prev = -1,
        .next = list->head,
        .value = value
    };
    if (listIsEmpty(list))
        list->tail = index;
    else
        list->data[list->head].prev = index;
    list->head = index;
    ++list->size;
    return true;
}

bool listPushBack(List * const list, const int value) {
    if (listIsFull(list))
        return false;
    const ptrdiff_t index = list->size;
        list->data[index] = (Node) {
        .prev = list->tail,
        .next = -1,
        .value = value
    };
    if (listIsEmpty(list))
        list->head = index;
    else
        list->data[list->tail].next = index;
    list->tail = index;
    ++list->size;
    return true;
}

bool listPopFront(List * const list) {
    if (listIsEmpty(list))
        return false;
    listUnlink(list, list->head);
    return true;
}

bool listPopBack(List * const list) {
    if (listIsEmpty(list))
        return false;
    listUnlink(list, list->tail);
    return true;
}

bool listErase(List * const list, const int value) {
    for (ptrdiff_t index = list->head; index >= 0; index = list->data[index].next)
        if (list->data[index].value == value) {
            listUnlink(list, index);
            return true;
        }
    return false;
}

bool listIsEmpty(const List * const list) {
    return list->size == 0;
}

bool listIsFull(const List * const list) {
    return list->size == MAX_SIZE;
}

size_t listSize(const List * const list) {
    return list->size;
}

void listPrint(const List * const list) {
    for (ptrdiff_t index = list->head; index >= 0; index = list->data[index].next)
        if (list->data[index].next >= 0)
            printf("%d  ", list->data[index].value);
        else
            printf("%d", list->data[index].value);
}

void listDebugPrint(const List * const list) {
    printf("List: { head: %td, tail: %td, size: %zu }\n",
        list->head, list->tail, list->size
    );
    for (size_t i = 0; i < list->size; ++i)
        printf("Node: { prev: %td, next: %td, value: %d }\n",
            list->data[i].prev, list->data[i].next, list->data[i].value
        );
}

ListIterator listIteratorBegin(List * const list) {
    return (ListIterator) { .list = list, .index = list->head };
}

ListIterator listIteratorEnd(List * const list) {
    return (ListIterator) { .list = list, .index = -1 };
}

bool listIteratorGet(const ListIterator *iterator, int *ptr) {
    const List * const list = iterator->list;
    const ptrdiff_t index = iterator->index;
    if (index == -1)
        return false;
    *ptr = list->data[index].value;
    return true;
}

bool listIteratorSet(ListIterator *iterator, int value) {
    List * const list = iterator->list;
    const ptrdiff_t index = iterator->index;
    if (index == -1)
        return false;
    list->data[index].value = value;
    return true;
}

bool listIteratorInsert(ListIterator *iterator, const int value) {
    List * const list = iterator->list;
    if (listIsFull(list))
        return false;
    const ptrdiff_t index = iterator->index;
    if (index == -1)
        return listPushBack(list, value);
    assert(index >= 0 && index < listSize(list));
    const ptrdiff_t newIndex = list->size, prev = list->data[index].prev;
    list->data[newIndex] = (Node) {
        .prev = prev,
        .next = index,
        .value = value
    };
    if (list->head == index)
        list->head = newIndex;
    else
        list->data[prev].next = newIndex;
    list->data[index].prev = newIndex;
    ++list->size;
    return true;
}

bool listIteratorErase(ListIterator *iterator) {
    List * const list = iterator->list;
    const ptrdiff_t index = iterator->index;
    if (index == -1 || listIsEmpty(list))
        return false;
    iterator->index = list->data[index].next;
    listUnlink(list, index);
    return true;
}

bool listIteratorNext(ListIterator *iterator) {
    List * const list = iterator->list;
    const ptrdiff_t index = iterator->index;
    assert(index >= -1 && index < listSize(list));
    if (iterator->index == -1)
        return false;
    iterator->index = list->data[index].next;
    return true;
}

bool listIteratorPrev(ListIterator *iterator) {
    List * const list = iterator->list;
    const ptrdiff_t index = iterator->index;
    assert(index >= -1 && index < listSize(list));
    if (iterator->index == -1) {
        if (listIsEmpty(list))
            return false;
        iterator->index = list->tail;
        return true;
    }
    iterator->index = list->data[index].prev;
    return true;
}

static void listUnlink(List * const list, const size_t index) {
    assert(index < list->size);
    Node * const node = list->data + index;
    if (list->head == index)
        list->head = node->next;
    else
        list->data[node->prev].next = node->next;
    if (list->tail == index)
        list->tail = node->prev;
    else
        list->data[node->next].prev = node->prev;
    --list->size;

    const size_t last = list->size;
    if (index == last)
        return;
    *node = list->data[last];
    if (list->head == last)
        list->head = index;
    else
        list->data[node->prev].next = index;
    if (list->tail == last)
        list->tail = index;
    else
        list->data[node->next].prev = index;
}

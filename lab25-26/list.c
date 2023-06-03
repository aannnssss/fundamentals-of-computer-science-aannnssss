#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <errno.h>
#include "list.h"
#include "sort.h"

#define MAX_SIZE (100U)

bool create(List* const list) {
    Node* const ptr = malloc(MAX_SIZE * sizeof(Node));
    if (ptr == NULL)
        return false;
    list->data = ptr;
    list->head = list->tail = -1;
    list->size = 0;
    return true;
}

bool pushFront(List * const list, int value) {
    if (list->size == MAX_SIZE)
        return false;
    const ptrdiff_t index = list->size;
    list->data[index].value = value;
    list->data[index].prev = -1;
    list->data[index].next = list->head;
    list->head = index;
    if (list->size == 0)
        list->tail = index;
    else
        list->data[list->head].prev = index;
    ++list->size;
    return true;
}

bool pushBack(List * const list, int value) {
    if (list->size == MAX_SIZE)
        return false;
    const ptrdiff_t index = list->size;
    list->data[index].value = value;
    list->data[index].prev = list->tail;
    list->data[index].next = -1;
    if (list->size == 0)
        list->head = index;
    else
        list->data[list->tail].next = index;
    list->tail = index;
    ++list->size;
    return true;
}
bool popFront(List * const list) {
    if (list->size == 0)
        return false;
    unlink(list, list->head);
    return true;
}

bool popBack(List * const list) {
    if (list->size == 0)
        return false;
    unlink(list, list->tail);
    return true;
}

bool isEmpty(const List * const list) {
    return list->size == 0;
}

void printList(const List * const list) {
    for (ptrdiff_t index = list->head; index != -1; index = list->data[index].next)
        if (list->data[index].next != -1)
            printf("%d  ", list->data[index].value);
        else
            printf("%d", list->data[index].value);
}

void printDebugList(const List * const list) {
    printf("List size: %zu\n", list->size);
    printf("List head: %zu\n", list->head);
    printf("List tail: %zu\n", list->tail);
    printf("List values:\n");
    for (ptrdiff_t i = 0; i < list->size; i++) {
        printf("value: %d, prev: %td, next: %td\n", list->data[i].value, list->data[i].prev, list->data[i].next);
    }
}

size_t listSize(const List * const list) {
    return list->size;
}

void clear(List * const list) {
    list->head = list->tail = -1;
    list->size = 0;
}

void destroy(List * const list) {
    free(list->data);
}

void unlink(List * const list, size_t index) {
    printf("index: %zu, list->size: %zu\n", index, list->size);
    swapLast(list, index);
    index = list->size - 1;
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
}

void swapLast(List * const list, const size_t index) {
    assert(index < list->size);
    const size_t lastIndex = list->size - 1;
    if (index >= lastIndex)
        return;
    Node * const last = list->data + lastIndex,
        * const byIndex = list->data + index;
    const Node tmp = *byIndex;
    *byIndex = *last;
    *last = tmp;

    if (list->head == index) {
        list->head = lastIndex;
        list->data[byIndex->prev].next = index;
    } else if (list->head == lastIndex) {
        list->head = index;
        list->data[last->prev].next = lastIndex;
    } else {
        list->data[byIndex->prev].next = index;
        list->data[last->prev].next = lastIndex;
    }

    if (list->tail == index) {
        list->tail = lastIndex;
        list->data[byIndex->next].prev = index;
    } else if (list->tail == lastIndex) {
        list->tail = index;
        list->data[last->next].prev = lastIndex;
    } else {
        list->data[byIndex->next].prev = index;
        list->data[last->next].prev = lastIndex;
    }

}
bool erase(List * const list, int value) {
    for (ptrdiff_t index = list->head; index != -1; index = list->data[index].next)
        if (list->data[index].value == value) {
            unlink(list, index);
            return true;
        }
    return false;
}

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int vectorCreate(Vector * const v, size_t initialCapacity) {
    if (initialCapacity == 0)
        v->data = NULL;
    else {
        v->data = (Elem *) malloc(sizeof(Elem) * initialCapacity);
        if (v->data == NULL)
            return errno;
    }
    v->capacity = initialCapacity;
    v->size = 0;
    return 0;
}

void vectorClear(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}

void vectorDestroy(Vector * const v) {
    free(v->data);
    v->capacity = v->size = 0;
}

int vectorPushBack(Vector * const v, const Elem * const elem) {
    if (v->size == v->capacity) {
        v->capacity++;
        Elem *newData = (Elem *)realloc(v->data, sizeof(Elem) * v->capacity);
        if (newData == NULL)
            return errno;
        v->data = newData;
    }
    v->data[v->size++] = *elem;
    return 0;
}
void vectorPrint(Vector * v) {
    if (v == NULL)
        return;
    printf("Matrix in one vector:\n");
    for (int i = 0; i < v->capacity; ++i) {
        printf("%ld ", v->data[i].j);
        printf("%d ", v->data[i].value);
    }
    printf("\n\n");
}


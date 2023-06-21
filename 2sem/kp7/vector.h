#ifndef VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef struct {
    ptrdiff_t j;
    union {
        int value;
        ptrdiff_t i;
    };
} Elem;

typedef struct {
    Elem *data;
    size_t capacity, size;
} Vector;

typedef struct {
    Vector vector;
    size_t m, n;
} Matrix;

int vectorCreate(Vector * const v, size_t initialCapacity);

void vectorClear(Vector *v);

void vectorDestroy(Vector * const v);

int vectorPushBack(Vector * const v, const Elem * const elem);

void vectorPrint(Vector * v);

#endif //VECTOR_H

#ifndef MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

int matrixCreate(Matrix *matrix);

void matrixDestroy(Matrix *matrix);

int matrixInput(FILE * f, Matrix *matrix);

int matrixGet(Matrix *matrix,  size_t index1,  size_t index2);

int matrixSet(Matrix *matrix,  size_t index1,  size_t index2,  int value);

void matrixPrint(Matrix *matrix);

void matrixTask(Matrix *matrix);

#endif//MATRIX_H

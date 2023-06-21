#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#include "vector.h"
#include "matrix.h"

int matrixCreate(Matrix * const matrix) {
    const int err = vectorCreate(&matrix->vector, 1);
    if (err != 0)
        return err;
    vectorPushBack(&matrix->vector, &(Elem) { .j = -1, .i = -1 });
    matrix->m = matrix->n = 0;
    return 0;
}

void matrixDestroy(Matrix *matrix) {
    vectorDestroy(&matrix->vector);
    matrix->m = matrix->n = 0;
    free(matrix);
}

int matrixInput(FILE *f, Matrix *matrix) {
    size_t m, n;
    if (fscanf(f, "%zu%zu", &m, &n) != 2)
        return errno;
    vectorClear(&matrix->vector);
    matrix->m = m;
    matrix->n = n;
    for (size_t i = 0; i < m; ++i) {
        bool flag = false;
        for (size_t j = 0; j < n; ++j) {
            int value;
            if (fscanf(f, "%d", &value) != 1)
                return errno;
            if (value == 0)
                continue;
            Elem elem1 = { .j = -1, .i = i };
            if (!flag && vectorPushBack(&matrix->vector, &elem1) != 0)
                return errno;
            Elem elem2 = { .j = j, .value = value };
            if (vectorPushBack(&matrix->vector, &elem2) != 0)
                return errno;
            flag = true;
        }
    }
    Elem elem3 = { .j = -1, .i = -1 };
    if (vectorPushBack(&matrix->vector, &elem3) != 0)
        return errno;
    return 0;
}


int matrixGet(Matrix *  matrix,  size_t index1,  size_t index2) {
    if (matrix->m <= index1 || matrix->n <= index2)
        return EINVAL;
    size_t p = 0, q = 0;
    int ans = 0;
    for (int i = 0; i < matrix->vector.capacity - 1; ++i) {
        if (matrix->vector.data[i].j == -1) {
            p = matrix->vector.data[i].i;
        } 
        if (matrix->vector.data[i].j != -1) {
            q = matrix->vector.data[i].j;
            if (p == index1 && q == index2) ans = matrix->vector.data[i].value;
        }
    }
    return ans;
}

int matrixSet(Matrix *  matrix,  size_t index1,  size_t index2,  int value) {
    if (matrix->m <= index1 || matrix->n <= index2)
        return EINVAL;
    size_t p = 0, q = 0;
    for (int i = 0; i < matrix->vector.capacity - 1; ++i) {
        if (matrix->vector.data[i].j == -1) {
            p = matrix->vector.data[i].i;
        } 
        if (matrix->vector.data[i].j != -1) {
            q = matrix->vector.data[i].j;
            if (p == index1 && q == index2)  {
                matrix->vector.data[i].value = value;
            }
        }
    }
    return 0;
}

void matrixPrint(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Matrix is null!\n");
        return;
    }

    printf("%zu %zu\n", matrix->m, matrix->n);
    for (int i = 0; i < matrix->m; ++i)
    {
        for (int j = 0; j < matrix->n; ++j)
        {
            int elem = matrixGet(matrix, i, j);
            if (elem == EINVAL)
            {
                printf("Error getting element at (%d, %d)\n", i, j);
                return;
            }
            printf("%d ", elem);
        }
        printf("\n");
    }
    printf("\n");
}

void matrixTask(Matrix *matrix) {
    int max_nonzero = -1;
    int *row_nonzero = calloc(matrix->m, sizeof(int));
    int n_nonzero = 0;

    for (int i = 0; i < matrix->m; ++i) {
        int nonzero_count = 0;
        for (int j = 0; j < matrix->n; ++j) {
            int elem = matrixGet(matrix, i, j);
            if (elem != 0) {
                nonzero_count++;
            }
        }
        if (nonzero_count > max_nonzero)
            max_nonzero = nonzero_count;

        row_nonzero[i] = nonzero_count;
    }

    for (int i = 0; i < matrix->m; ++i) {
        if (row_nonzero[i] == max_nonzero) {
            printf("Row %d, %d non-zero elements:\n", i, max_nonzero);
            int row_sum = 0;

            for (int j = 0; j < matrix->n; ++j) {
                int elem = matrixGet(matrix, i, j);
                printf("%d ", elem);
                row_sum += elem;
            }

            printf("\n");
            printf("Sum = %d\n", row_sum);
            printf("\n");
        }
    }

    for (int i = 0; i < matrix->m; i++) {
        if (row_nonzero[i] > 0) {
            n_nonzero++;
        }
    }

    if (n_nonzero == 0)
        printf("No non-zero rows\n");

    free(row_nonzero);
}

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No file name provided.\n");
        return 0;
    }
    char *name = argv[1];
    FILE *f = fopen(name, "r");
    if (f == NULL) {
        printf("Can not open file\n");
        return 0;
    }
    Matrix *matrix = malloc(sizeof(Matrix));
    matrixCreate(matrix);
    matrixInput(f, matrix);
    matrixPrint(matrix);
    vectorPrint(&matrix->vector);
    matrixTask(matrix);
    vectorClear(&matrix->vector);
    free(matrix);
    fclose(f);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <errno.h>
#include "list.h"
#include "sort.h"

bool procedure(List * const list, const int value) {
    return true;
}

bool sort(List * const list) {
    List tmp;
    if (!listCreate(&tmp))
        return false;
    while (!listIsEmpty(list)) {
        int value;
        listFront(list, &value);
        listPopFront(list);
        if (!procedure(&tmp, value)) {
            listDestroy(&tmp);
            return false;
        }
    }
    listDestroy(list);
    *list = tmp;
    return true;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "sort.h"

bool procedure(List * const list, const int newValue) { 
    ListIterator iterator = listIteratorEnd(list);
    while (listIteratorPrev(&iterator)) {
        int value;
        if (!listIteratorGet(&iterator, &value)) {
            return listPushFront(list, newValue);
        }
        //printf("New Value: %d value: %d\n",newValue, value);
        if (newValue >= value)
            break;
    }
    if (!listIteratorInsert(&iterator, newValue)) {
        return false;
    }
    return true;
}

bool sort(List * const list) {
    List tmp;
    if (!listCreate(&tmp)) {
        return false;
    }
    while (!listIsEmpty(list)) {
        int value;
        listFront(list, &value);
        //listPrint(&tmp);
        //printf("value front: %d\n",value);
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


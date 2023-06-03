#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <errno.h>
#include "list.h"
#include "sort.h"

bool procedure(List * const list1, int ch) {
    
    if (list1->size == MAX_SIZE)
        return false;
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = ch;
    node->prev = -1;
    node->next = -1;

    if (list1->size == 0 || ch < list1->data[0].value) {
        pushFront(list1, ch);
    } else if (ch >= list1->data[list1->size-1].value) {
        pushBack(list1, ch);
    } else {
        for (ptrdiff_t index = list1->head; index != -1; index = list1->data[index].next) {      
            if (list1->data[index].value <= ch) {
                continue;
            } else {
                list1->data[node->prev].next = node->next; 
                list1->data[node->next].prev = node->prev;
                ++list1->size;
            }
        }
    }
    free(node);
    return true;
}

void sort(List * const list) {   
    List list1;  
    create(&list1);  
    while (!isEmpty(list)) {  
        int ch = list->data[0].value;
        popFront(list);  
        procedure(&list1, ch);  
    }  
    List tmp = *list; 
    *list = list1; 
    list1 = tmp; 
    clear(&list1); 
}  

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "list.h"

List* listCreate() {
    List* list = malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;
    return list;
}

bool nodeCreate(int data, Node** node) { 
    *node = malloc(sizeof(Node)); 
    if (*node == NULL) {
        return false; 
    }
    (*node)->data = data; 
    (*node)->prev = NULL; 
    (*node)->next = NULL; 
    return true;
}

bool listPushFront(List* list, int data) {
    Node* node;
    if (!nodeCreate(data, &node)) {
        return false;
    }
    if (list->size == 0) {
        list->head = node;
        node->next = node;
        node->prev = node;
    } else {
        Node* head = list->head;
        Node* tail = head->prev;
        node->next = head;
        node->prev = tail;
        tail->next = node;
        head->prev = node;
        list->head = node;
    }
    list->size++;
    return true;
}

bool listPushBack(List* list, int data) {
    Node* node;
    if (!nodeCreate(data, &node)) {
        return false;
    }
    if (list->size == 0) {
        list->head = node;
        node->next = node;
        node->prev = node;
    } else {
        Node* head = list->head;
        Node* tail = head->prev;
        node->next = head;
        node->prev = tail;
        tail->next = node;
        head->prev = node;
    }
    list->size++;
}

bool listIsEmpty(List *list) {
    return list->size == 0;
}

bool listPopFront(List* list) {
    if (listIsEmpty(list)) {
        return false;
    }
    Node* head = list->head;
    Node* tail = head->prev;
    if (list->size == 1) {
        list->head = NULL;
    } else {
        Node* new_head = head->next;
        new_head->prev = tail;
        tail->next = new_head;
        list->head = new_head;
    }
    free(head);
    list->size--;
    return true;
}

bool listPopBack(List* list) {
    if (listIsEmpty(list)) {
        return false;
    }
    Node* head = list->head;
    Node* tail = head->prev;
    if (list->size == 1) {
        list->head = NULL;
    } else {
        Node* new_tail = tail->prev;
        new_tail->next = head;
        head->prev = new_tail;
    }
    free(tail);
    list->size--;
    return true;
}

ptrdiff_t listSize(List* list) {
    return list->size;
}

ListIterator listIteratorBegin(const List * const list) { 
    return (ListIterator) { .node = list->head, .list = (List *) list}; 
} 

ListIterator listIteratorEnd(const List * const list) {
    return (ListIterator) { .node = list->head->prev, .list = (List *) list};
}

ListIterator *listIteratorNext(ListIterator * const it) {
    it->node = it->node->next;
    return it;
}
 
bool listPrint(List *list) {
    if (listIsEmpty(list)) {
        printf("List is not empty\n");
        return false;
    }
    ListIterator it = listIteratorBegin(list);
    ListIterator end = listIteratorEnd(list);
    for(; ; listIteratorNext(&it)) { 
        printf("%d ", it.node->data); 
        if (it.node == end.node)  
            break; 
    }
    printf("\n"); 
    return true;
}

bool nodeInsert(List *list, int index, int value) {  
    if (index < 0 || index > list->size) {
        printf("Index out of range\n");
        return false;
    }
    Node* new_node;
    if (!nodeCreate(value, &new_node)) {
        return false;
    }
    if (list->head == NULL) {
        list->head = new_node;
        new_node->prev = new_node;
        new_node->next = new_node;
    } else if (index == 0) {
        Node *tail = list->head->prev;
        new_node->prev = tail;
        new_node->next = list->head;
        list->head->prev = new_node;
        tail->next = new_node;
        list->head = new_node;
    } else {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        current->next->prev = new_node;
        new_node->next = current->next;
        current->next = new_node;
        new_node->prev = current;
    }
    list->size++;
    return true;
}

bool nodeDelete(List *list, int index) { 
    if (index < 0 || index >= list->size) {
        printf("Index out of range\n");
        return false;
    }
    if (list->head == NULL) {
        return false;
    }
    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
    } else if (index == 0) {
        Node *tail = list->head->prev;
        Node *new_head = list->head->next;
        tail->next = new_head;
        new_head->prev = tail;
        free(list->head);
        list->head = new_head;
    } else {
        Node *current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
    list->size--;
    return true;
}

bool nodeGet(Node** node, List* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of range\n");
        return false;
    }
    ListIterator it = listIteratorBegin(list);
    ListIterator end = listIteratorEnd(list);
    int i = 0;
    for(; i < index && it.node != end.node; listIteratorNext(&it), i++);
    *node=it.node;
    return true;
}

void Swap(List *list, int k) {
    Node *first, *second;
    if (k == 0) {
        nodeGet(&first, list, 1);
        nodeGet(&second, list, list->size - 1);
    } else if (k == list->size - 1) {
        nodeGet(&first, list, 0);
	nodeGet(&second, list, list->size - 2);
    } else {
	nodeGet(&first, list, k - 1);
	nodeGet(&second, list, k + 1);
    }
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

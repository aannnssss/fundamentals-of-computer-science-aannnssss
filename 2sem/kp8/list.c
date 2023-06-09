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

Node* nodeCreate(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void listPushFront(List* list, int data) {
    Node* node = nodeCreate(data);
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
}

void listPushBack(List* list, int data) {
    Node* node = nodeCreate(data);
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

void listPopFront(List* list) {
    if (listIsEmpty(list)) {
        printf("List is not empty\n");
        return;
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
}

void listPopBack(List* list) {
    if (listIsEmpty(list)) {
        printf("List is not empty\n");
        return;
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
}

int listSize(List* list) {
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
 
void listPrint(List *list) {
    if (listIsEmpty(list)) {
        printf("List is not empty\n");
        return;
    }
    ListIterator it = listIteratorBegin(list);
    ListIterator end = listIteratorEnd(list);
    for(; ; listIteratorNext(&it)) { 
        printf("%d ", it.node->data); 
        if (it.node == end.node)  
            break; 
    }
    printf("\n"); 
}

void nodeInsert(List *list, int index, int value) {  
    if (index < 0 || index > list->size) {
        printf("Index out of range\n");
        return;
    }
    Node *new_node = nodeCreate(value);
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
}

void nodeDelete(List *list, int index) { 
    if (index < 0 || index >= list->size) {
        printf("Index out of range\n");
        return;
    }
    if (list->head == NULL) {
        return;
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
}

Node* nodeGet(List* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Index out of range\n");
        return NULL;
    }
    ListIterator it = listIteratorBegin(list);
    ListIterator end = listIteratorEnd(list);
    int i = 0;
    for(; i < index && it.node != end.node; listIteratorNext(&it), i++);
    return it.node;
}

void Swap(List *list, int k) {
    Node *first, *second;
    if (k == 0) {
        first = nodeGet(list, 1);
		second = nodeGet(list, list->size - 1);
    } else if (k == list->size - 1) {
        first = nodeGet(list, 0);
		second = nodeGet(list, list->size - 2);
    } else {
		first = nodeGet(list, k - 1);
		second = nodeGet(list, k + 1);
    }
	int temp = first->data;
	first->data = second->data;
	second->data = temp;
}

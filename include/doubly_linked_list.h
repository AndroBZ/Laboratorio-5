#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef struct DoublyNode {
    int data;
    struct DoublyNode *next;
    struct DoublyNode *prev;
} DoublyNode;

typedef struct {
    DoublyNode *head;
    DoublyNode *tail;
} DoublyLinkedList;

DoublyLinkedList* create_double_list();
void insert_double_start(DoublyLinkedList *list, int data);
void insert_double_end(DoublyLinkedList *list, int data);
void delete_double_by_data(DoublyLinkedList *list, int data);
void print_double_forward(DoublyLinkedList *list);
void print_double_backward(DoublyLinkedList *list);
void free_double_list(DoublyLinkedList *list);

#endif // DOUBLY_LINKED_LIST_H

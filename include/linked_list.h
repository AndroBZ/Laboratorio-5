#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

LinkedList* create_list();
void insert_start(LinkedList *list, int data);
void insert_end(LinkedList *list, int data);
void insert_position(LinkedList *list, int data, size_t position);
void delete_by_data(LinkedList *list, int data);
int search_element(LinkedList *list, int data);
void print_list(LinkedList *list);
void free_list(LinkedList *list);

#endif // LINKED_LIST_H

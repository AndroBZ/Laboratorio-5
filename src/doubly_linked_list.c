#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

DoublyLinkedList* create_double_list() {
    DoublyLinkedList *list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insert_double_start(DoublyLinkedList *list, int data) {
    if (!list) return;
    DoublyNode *new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
    if (!new_node) return;

    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node;
    }
    list->head = new_node;
}

void insert_double_end(DoublyLinkedList *list, int data) {
    if (!list) return;
    DoublyNode *new_node = (DoublyNode*)malloc(sizeof(DoublyNode));
    if (!new_node) return;

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    list->tail = new_node;
}

void delete_double_by_data(DoublyLinkedList *list, int data) {
    if (!list || !list->head) return;

    DoublyNode *current = list->head;
    while (current && current->data != data) {
        current = current->next;
    }

    if (!current) return;

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    free(current);
}

void print_double_forward(DoublyLinkedList *list) {
    if (!list) return;
    DoublyNode *temp = list->head;
    printf("Forward: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void print_double_backward(DoublyLinkedList *list) {
    if (!list) return;
    DoublyNode *temp = list->tail;
    printf("Backward: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void free_double_list(DoublyLinkedList *list) {
    if (!list) return;
    DoublyNode *current = list->head;
    DoublyNode *next_node;
    while (current) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(list);
}

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* create_list() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) return NULL;
    list->head = NULL;
    return list;
}

void insert_start(LinkedList *list, int data) {
    if (!list) return;
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return;
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void insert_end(LinkedList *list, int data) {
    if (!list) return;
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return;
    new_node->data = data;
    new_node->next = NULL;

    if (!list->head) {
        list->head = new_node;
        return;
    }

    Node *temp = list->head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_position(LinkedList *list, int data, size_t position) {
    if (!list) return;
    if (position == 0) {
        insert_start(list, data);
        return;
    }

    Node *temp = list->head;
    for (size_t i = 0; temp && i < position - 1; i++) {
        temp = temp->next;
    }

    if (!temp) return;

    Node *new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return;
    new_node->data = data;
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_by_data(LinkedList *list, int data) {
    if (!list || !list->head) return;

    Node *temp = list->head;
    if (temp->data == data) {
        list->head = temp->next;
        free(temp);
        return;
    }

    Node *prev = NULL;
    while (temp && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return;

    prev->next = temp->next;
    free(temp);
}

int search_element(LinkedList *list, int data) {
    if (!list) return 0;
    Node *temp = list->head;
    while (temp) {
        if (temp->data == data) return 1;
        temp = temp->next;
    }
    return 0;
}

void print_list(LinkedList *list) {
    if (!list) return;
    Node *temp = list->head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_list(LinkedList *list) {
    if (!list) return;
    Node *current = list->head;
    Node *next_node;
    while (current) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(list);
}

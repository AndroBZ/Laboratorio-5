#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* create_stack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack *stack, int data) {
    if (!stack) return;
    StackNode *new_node = (StackNode*)malloc(sizeof(StackNode));
    if (!new_node) return;

    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int pop(Stack *stack, int *out_value) {
    if (!stack || is_empty(stack) || !out_value) return 0;

    StackNode *temp = stack->top;
    *out_value = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return 1;
}

int peek(Stack *stack, int *out_value) {
    if (!stack || is_empty(stack) || !out_value) return 0;
    *out_value = stack->top->data;
    return 1;
}

int is_empty(Stack *stack) {
    return (stack == NULL || stack->top == NULL);
}

void print_stack(Stack *stack) {
    if (!stack) return;
    if (is_empty(stack)) {
        printf("Pila vacía\n");
        return;
    }
    StackNode *temp = stack->top;
    printf("Top -> ");
    while (temp) {
        printf("[%d]", temp->data);
        if (temp->next) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void free_stack(Stack *stack) {
    if (!stack) return;
    StackNode *current = stack->top;
    StackNode *next_node;
    while (current) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(stack);
}

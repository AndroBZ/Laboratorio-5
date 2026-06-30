#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
    size_t size;
} Stack;

Stack* create_stack();
void push(Stack *stack, int data);
int pop(Stack *stack, int *out_value);
int peek(Stack *stack, int *out_value);
int is_empty(Stack *stack);
void print_stack(Stack *stack);
void free_stack(Stack *stack);

#endif // STACK_H

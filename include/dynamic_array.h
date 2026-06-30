#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t capacity;
    size_t size;
} DynamicArray;

DynamicArray* create_array(size_t initial_capacity);
void append_element(DynamicArray *array, int element);
void delete_element(DynamicArray *array, size_t index);
int get_element(DynamicArray *array, size_t index, int *out_value);
void print_array(DynamicArray *array);
void free_array(DynamicArray *array);

#endif // DYNAMIC_ARRAY_H

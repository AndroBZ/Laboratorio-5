#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray* create_array(size_t initial_capacity) {
    DynamicArray *array = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (!array) return NULL;

    array->data = (int*)malloc(initial_capacity * sizeof(int));
    if (!array->data) {
        free(array);
        return NULL;
    }

    array->capacity = initial_capacity;
    array->size = 0;
    return array;
}

void append_element(DynamicArray *array, int element) {
    if (!array) return;

    if (array->size >= array->capacity) {
        size_t new_capacity = array->capacity * 2;
        int *new_data = (int*)realloc(array->data, new_capacity * sizeof(int));
        if (!new_data) return;

        array->data = new_data;
        array->capacity = new_capacity;
    }

    array->data[array->size] = element;
    array->size++;
}

void delete_element(DynamicArray *array, size_t index) {
    if (!array || index >= array->size) return;

    for (size_t i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }

    array->size--;
}

int get_element(DynamicArray *array, size_t index, int *out_value) {
    if (!array || index >= array->size || !out_value) return 0;
    
    *out_value = array->data[index];
    return 1;
}

void print_array(DynamicArray *array) {
    if (!array) return;
    
    printf("[");
    for (size_t i = 0; i < array->size; i++) {
        printf("%d", array->data[i]);
        if (i < array->size - 1) printf(", ");
    }
    printf("]\n");
}

void free_array(DynamicArray *array) {
    if (!array) return;
    if (array->data) free(array->data);
    free(array);
}

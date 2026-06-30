#include <stdio.h>
#include "dynamic_array.h"
#include "linked_list.h"
#include "doubly_linked_list.h"
#include "stack.h"

int main() {
    printf("==================================================\n");
    printf("   LABORATORIO 5: ESTRUCTURAS DE DATOS GLOBALES   \n");
    printf("==================================================\n\n");

    // 1. PRUEBAS DE ARREGLO DINÁMICO
    printf(">>> 1. PRUEBAS DE ARREGLO DINÁMICO <<<\n");
    DynamicArray *arr = create_array(5);
    if (arr) {
        insert_element(arr, 10);
        insert_element(arr, 20);
        insert_element(arr, 30);
        print_array(arr);
        free_array(arr);
    }
    printf("\n");

    // 2. PRUEBAS DE LISTA ENLAZADA SIMPLE
    printf(">>> 2. PRUEBAS DE LISTA ENLAZADA SIMPLE <<<\n");
    LinkedList *lista_simple = create_list();
    if (lista_simple) {
        insert_start(lista_simple, 10);
        insert_end(lista_simple, 20);
        insert_position(lista_simple, 15, 1);
        print_list(lista_simple);
        free_list(lista_simple);
    }
    printf("\n");

    // 3. PRUEBAS DE LISTA DOBLEMENTE ENLAZADA
    printf(">>> 3. PRUEBAS DE LISTA DOBLEMENTE ENLAZADA <<<\n");
    DoublyLinkedList *lista_doble = create_double_list();
    if (lista_doble) {
        insert_double_start(lista_doble, 50);
        insert_double_end(lista_doble, 60);
        print_double_forward(lista_doble);
        free_double_list(lista_doble);
    }
    printf("\n");

    // 4. PRUEBAS DE PILA (STACK)
    printf(">>> 4. PRUEBAS DE PILA (STACK) <<<\n");
    Stack *mi_pila = create_stack();
    if (mi_pila) {
        push(mi_pila, 100);
        push(mi_pila, 200);
        print_stack(mi_pila);
        free_stack(mi_pila);
    }
    
    printf("\n==================================================\n");
    printf("   ¡TODAS LAS PRUEBAS CONCLUIDAS EXITOSAMENTE!    \n");
    printf("==================================================\n");

    return 0;
}

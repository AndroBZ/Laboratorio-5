#include "stack.h"
#include <stdio.h>

int main() {
    printf("=== PRUEBAS DE PILA (STACK) ===\n\n");

    printf("1. Creando pila vacía...\n");
    Stack *mi_pila = create_stack();
    if (!mi_pila) {
        printf("Error al asignar memoria para la pila.\n");
        return 1;
    }
    print_stack(mi_pila);

    printf("\n2. Apilando elementos (Push: 100, 200, 300)...\n");
    push(mi_pila, 100);
    push(mi_pila, 200);
    push(mi_pila, 300);
    print_stack(mi_pila);

    printf("\n3. Consultando el elemento en el tope (Peek)...\n");
    int valor_tope;
    if (peek(mi_pila, &valor_tope)) {
        printf("El elemento en el tope es: %d\n", valor_tope);
    }

    printf("\n4. Desapilando dos elementos (Pop)...\n");
    int valor_desapilado;
    if (pop(mi_pila, &valor_desapilado)) {
        printf("Desapilado: %d\n", valor_desapilado);
    }
    if (pop(mi_pila, &valor_desapilado)) {
        printf("Desapilado: %d\n", valor_desapilado);
    }
    print_stack(mi_pila);

    printf("\n5. Liberando memoria de la pila...\n");
    free_stack(mi_pila);
    printf("¡Memoria liberada exitosamente!\n");

    return 0;
}

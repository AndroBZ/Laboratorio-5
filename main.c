#include "dynamic_array.h"
#include <stdio.h>

int main() {
    printf("=== PRUEBAS DE ARREGLO DINÁMICO ===\n\n");

    printf("1. Creando arreglo dinámico con capacidad inicial de 2...\n");
    DynamicArray *mi_arreglo = create_array(2);
    if (!mi_arreglo) {
        printf("Error al asignar memoria para el arreglo.\n");
        return 1;
    }
    print_array(mi_arreglo);

    printf("\n2. Agregando elementos: 10, 20, 30...\n");
    append_element(mi_arreglo, 10);
    append_element(mi_arreglo, 20);
    append_element(mi_arreglo, 30);
    print_array(mi_arreglo);
    printf("Tamaño actual: %zu, Capacidad actual: %zu\n", mi_arreglo->size, mi_arreglo->capacity);

    printf("\n3. Obteniendo elemento en el índice 1...\n");
    int valor;
    if (get_element(mi_arreglo, 1, &valor)) {
        printf("El valor en el índice 1 es: %d\n", valor);
    } else {
        printf("Índice fuera de rango.\n");
    }

    printf("\n4. Eliminando el elemento en el índice 0 (el 10)...\n");
    delete_element(mi_arreglo, 0);
    print_array(mi_arreglo);

    printf("\n5. Liberando memoria del arreglo...\n");
    free_array(mi_arreglo);
    printf("¡Memoria liberada exitosamente!\n");

    return 0;
}

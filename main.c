#include "linked_list.h"
#include <stdio.h>

int main() {
    printf("=== PRUEBAS DE LISTA ENLAZADA SIMPLE ===\n\n");

    printf("1. Creando lista enlazada vacía...\n");
    LinkedList *mi_lista = create_list();
    if (!mi_lista) {
        printf("Error al asignar memoria para la lista.\n");
        return 1;
    }
    print_list(mi_lista);

    printf("\n2. Insertando elementos (10 al inicio, 20 al final, 15 en posición 1)...\n");
    insert_start(mi_lista, 10);
    insert_end(mi_lista, 20);
    insert_position(mi_lista, 15, 1);
    print_list(mi_lista);

    printf("\n3. Buscando el elemento 15...\n");
    if (search_element(mi_lista, 15)) {
        printf("¡El elemento 15 sí existe en la lista!\n");
    } else {
        printf("Elemento no encontrado.\n");
    }

    printf("\n4. Eliminando el elemento 10...\n");
    delete_by_data(mi_lista, 10);
    print_list(mi_lista);

    printf("\n5. Liberando memoria de la lista...\n");
    free_list(mi_lista);
    printf("¡Memoria liberada exitosamente!\n");

    return 0;
}

#include "doubly_linked_list.h"
#include <stdio.h>

int main() {
    printf("=== PRUEBAS DE LISTA DOBLEMENTE ENLAZADA ===\n\n");

    printf("1. Creando lista doble vacía...\n");
    DoublyLinkedList *mi_lista_doble = create_double_list();
    if (!mi_lista_doble) {
        printf("Error al asignar memoria para la lista.\n");
        return 1;
    }
    print_double_forward(mi_lista_doble);

    printf("\n2. Insertando elementos (50 al inicio, 60 al final, 40 al inicio)...\n");
    insert_double_start(mi_lista_doble, 50);
    insert_double_end(mi_lista_doble, 60);
    insert_double_start(mi_lista_doble, 40);
    
    print_double_forward(mi_lista_doble);
    print_double_backward(mi_lista_doble);

    printf("\n3. Eliminando el elemento central (50)...\n");
    delete_double_by_data(mi_lista_doble, 50);
    
    print_double_forward(mi_lista_doble);
    print_double_backward(mi_lista_doble);

    printf("\n4. Liberando memoria de la lista doble...\n");
    free_double_list(mi_lista_doble);
    printf("¡Memoria liberada exitosamente!\n");

    return 0;
}

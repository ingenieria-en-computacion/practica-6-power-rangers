#include "../include/deque.h"
#include <stdio.h>

void print_int(int value) {
    printf("%d", value);
}

int main() {
    // Crear una bicola de enteros
    Deque_int* deque = deque_int_create();

    // Insertar elementos al frente
    deque_int_push_front(deque, 20);
    deque_int_push_front(deque, 10);

    // Insertar elementos al final
    deque_int_push_back(deque, 30);
    deque_int_push_back(deque, 40);

    printf("Bicola de enteros: ");
    deque_int_print(deque, print_int);

    // Eliminar del frente
    int val;
    deque_int_pop_front(deque, &val);
    printf("\nElemento eliminado del frente: %d\n", val);

    // Eliminar del final
    deque_int_pop_back(deque, &val);
    printf("Elemento eliminado del final: %d\n", val);

    printf("Bicola después de eliminar: ");
    deque_int_print(deque, print_int);

    // Liberar memoria
    deque_int_destroy(deque);

    return 0;
}

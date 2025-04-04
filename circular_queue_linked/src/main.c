#include "../include/circular_queue_linked.h"

void print_int(int value) {
    printf("%d", value);
}

int main() {
    DEFINE_CIRCULAR_QUEUE_LINKED(int, int);

    CircularQueue_int* q = cq_int_create();

    cq_int_enqueue(q, 10);
    cq_int_enqueue(q, 20);
    cq_int_enqueue(q, 30);

    printf("Cola circular: ");
    cq_int_print(q, print_int);

    int out;
    cq_int_dequeue(q, &out);
    printf("Elemento eliminado: %d\n", out);

    printf("Cola después de eliminar: ");
    cq_int_print(q, print_int);

    cq_int_destroy(q);

    return 0;
}

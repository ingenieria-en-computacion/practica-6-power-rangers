#define CIRCULAR_QUEUE_IMPLEMENTATION
#include "circular_queue.h"
#include <stdio.h>

void print_int(int value) { printf("%d ", value); }
void print_char(char value) { printf("%c ", value); }

int main() {
    CircularQueue_int* queue = circular_queue_int_create();
    circular_queue_int_enqueue(queue, 10);
    circular_queue_int_enqueue(queue, 20);
    circular_queue_int_enqueue(queue, 30);
    
    printf("Cola de enteros: ");
    circular_queue_int_print(queue, print_int);
    
    int val;
    circular_queue_int_dequeue(queue, &val);
    printf("Desencolado: %d\n", val);
    
    circular_queue_int_print(queue, print_int);
    circular_queue_int_destroy(queue);
    
    return 0;
}

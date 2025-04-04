// main.c
#include "../include/circular_queue_array.h"

void cq_init(CircularQueue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

bool cq_is_empty(CircularQueue* q) {
    return q->size == 0;
}

bool cq_is_full(CircularQueue* q) {
    return q->size == MAX_QUEUE_SIZE;
}

bool cq_enqueue(CircularQueue* q, int value) {
    if (cq_is_full(q)) return false;
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->size++;
    return true;
}

bool cq_dequeue(CircularQueue* q, int* out) {
    if (cq_is_empty(q)) return false;
    *out = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return true;
}

void cq_print(CircularQueue* q) {
    printf("Cola circular (array): [");
    for (int i = 0; i < q->size; ++i) {
        int index = (q->front + i) % MAX_QUEUE_SIZE;
        printf("%d", q->data[index]);
        if (i < q->size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    CircularQueue q;
    cq_init(&q);

    cq_enqueue(&q, 1);
    cq_enqueue(&q, 2);
    cq_enqueue(&q, 3);

    cq_print(&q);

    int value;
    cq_dequeue(&q, &value);
    printf("Desencolado: %d\n", value);

    cq_print(&q);

    return 0;
}

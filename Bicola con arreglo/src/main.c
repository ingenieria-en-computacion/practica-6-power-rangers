// main.c
#include "../include/deque_array.h"

void dq_init(Deque* d) {
    d->front = 0;
    d->rear = 0;
    d->size = 0;
}

bool dq_is_empty(Deque* d) {
    return d->size == 0;
}

bool dq_is_full(Deque* d) {
    return d->size == MAX_DEQUE_SIZE;
}

bool dq_push_back(Deque* d, int value) {
    if (dq_is_full(d)) return false;
    d->data[d->rear] = value;
    d->rear = (d->rear + 1) % MAX_DEQUE_SIZE;
    d->size++;
    return true;
}

bool dq_push_front(Deque* d, int value) {
    if (dq_is_full(d)) return false;
    d->front = (d->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    d->data[d->front] = value;
    d->size++;
    return true;
}

bool dq_pop_front(Deque* d, int* out) {
    if (dq_is_empty(d)) return false;
    *out = d->data[d->front];
    d->front = (d->front + 1) % MAX_DEQUE_SIZE;
    d->size--;
    return true;
}

bool dq_pop_back(Deque* d, int* out) {
    if (dq_is_empty(d)) return false;
    d->rear = (d->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    *out = d->data[d->rear];
    d->size--;
    return true;
}

void dq_print(Deque* d) {
    printf("Bicola (array): [");
    for (int i = 0; i < d->size; ++i) {
        int index = (d->front + i) % MAX_DEQUE_SIZE;
        printf("%d", d->data[index]);
        if (i < d->size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    Deque d;
    dq_init(&d);

    dq_push_back(&d, 1);
    dq_push_front(&d, 2);
    dq_push_back(&d, 3);

    dq_print(&d);

    int value;
    dq_pop_front(&d, &value);
    printf("Desencolado al frente: %d\n", value);

    dq_pop_back(&d, &value);
    printf("Desencolado al final: %d\n", value);

    dq_print(&d);

    return 0;
}

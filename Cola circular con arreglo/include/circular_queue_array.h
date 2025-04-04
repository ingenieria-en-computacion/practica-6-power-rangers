// circular_queue_array.h
#ifndef CIRCULAR_QUEUE_ARRAY_H
#define CIRCULAR_QUEUE_ARRAY_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} CircularQueue;

void cq_init(CircularQueue* q);
bool cq_is_empty(CircularQueue* q);
bool cq_is_full(CircularQueue* q);
bool cq_enqueue(CircularQueue* q, int value);
bool cq_dequeue(CircularQueue* q, int* out);
void cq_print(CircularQueue* q);

#endif

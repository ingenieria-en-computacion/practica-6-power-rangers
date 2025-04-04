// deque_array.h
#ifndef DEQUE_ARRAY_H
#define DEQUE_ARRAY_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_DEQUE_SIZE 10

typedef struct {
    int data[MAX_DEQUE_SIZE];
    int front;
    int rear;
    int size;
} Deque;

void dq_init(Deque* d);
bool dq_is_empty(Deque* d);
bool dq_is_full(Deque* d);
bool dq_push_front(Deque* d, int value);
bool dq_push_back(Deque* d, int value);
bool dq_pop_front(Deque* d, int* out);
bool dq_pop_back(Deque* d, int* out);
void dq_print(Deque* d);

#endif

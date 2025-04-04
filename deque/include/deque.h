#pragma once
#include <stdlib.h>
#include <stdbool.h>

#define DECLARE_DEQUE(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
        struct Node_##TYPE* prev; \
    } Node_##TYPE; \
    Node_##TYPE* node_##TYPE##_create(TYPE); \
    Node_##TYPE* node_##TYPE##_destroy(Node_##TYPE*); \
    \
    typedef struct { \
        Node_##TYPE* front; \
        Node_##TYPE* back; \
        size_t length; \
    } Deque_##TYPE; \
    \
    Deque_##TYPE* deque_##TYPE##_create(void); \
    void deque_##TYPE##_destroy(Deque_##TYPE* deque); \
    bool deque_##TYPE##_push_front(Deque_##TYPE* deque, TYPE data); \
    bool deque_##TYPE##_push_back(Deque_##TYPE* deque, TYPE data); \
    bool deque_##TYPE##_pop_front(Deque_##TYPE* deque, TYPE* out); \
    bool deque_##TYPE##_pop_back(Deque_##TYPE* deque, TYPE* out); \
    size_t deque_##TYPE##_length(const Deque_##TYPE* deque); \
    bool deque_##TYPE##_is_empty(const Deque_##TYPE* deque); \
    void deque_##TYPE##_print(const Deque_##TYPE* deque, void (*print_fn)(TYPE));

DECLARE_DEQUE(int)
DECLARE_DEQUE(char)
DECLARE_DEQUE(float)

#include "deque.h"
#include <stdio.h>

#define IMPLEMENT_DEQUE(TYPE) \
    Node_##TYPE* node_##TYPE##_create(TYPE data) { \
        Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
        new_node->data = data; \
        new_node->next = new_node->prev = NULL; \
        return new_node; \
    } \
    Node_##TYPE* node_##TYPE##_destroy(Node_##TYPE* node) { \
        if (node) free(node); \
        return NULL; \
    } \
    Deque_##TYPE* deque_##TYPE##_create(void) { \
        Deque_##TYPE* deque = malloc(sizeof(Deque_##TYPE)); \
        if (!deque) return NULL; \
        deque->front = deque->back = NULL; \
        deque->length = 0; \
        return deque; \
    } \
    void deque_##TYPE##_destroy(Deque_##TYPE* deque) { \
        if (!deque) return; \
        Node_##TYPE* current = deque->front; \
        while (current) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
        } \
        free(deque); \
    } \
    bool deque_##TYPE##_push_front(Deque_##TYPE* deque, TYPE data) { \
        if (!deque) return false; \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        if (deque->front) { \
            new_node->next = deque->front; \
            deque->front->prev = new_node; \
        } else { \
            deque->back = new_node; \
        } \
        deque->front = new_node; \
        deque->length++; \
        return true; \
    } \
    bool deque_##TYPE##_push_back(Deque_##TYPE* deque, TYPE data) { \
        if (!deque) return false; \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        if (deque->back) { \
            deque->back->next = new_node; \
            new_node->prev = deque->back; \
        } else { \
            deque->front = new_node; \
        } \
        deque->back = new_node; \
        deque->length++; \
        return true; \
    } \
    bool deque_##TYPE##_pop_front(Deque_##TYPE* deque, TYPE* out) { \
        if (!deque || !deque->front) return false; \
        Node_##TYPE* temp = deque->front; \
        *out = temp->data; \
        deque->front = temp->next; \
        if (deque->front) deque->front->prev = NULL; \
        else deque->back = NULL; \
        free(temp); \
        deque->length--; \
        return true; \
    } \
    bool deque_##TYPE##_pop_back(Deque_##TYPE* deque, TYPE* out) { \
        if (!deque || !deque->back) return false; \
        Node_##TYPE* temp = deque->back; \
        *out = temp->data; \
        deque->back = temp->prev; \
        if (deque->back) deque->back->next = NULL; \
        else deque->front = NULL; \
        free(temp); \
        deque->length--; \
        return true; \
    } \
    size_t deque_##TYPE##_length(const Deque_##TYPE* deque) { \
        return deque ? deque->length : 0; \
    } \
    bool deque_##TYPE##_is_empty(const Deque_##TYPE* deque) { \
        return deque ? deque->length == 0 : true; \
    } \
    void deque_##TYPE##_print(const Deque_##TYPE* deque, void (*print_fn)(TYPE)) { \
        if (!deque) return; \
        printf("["); \
        Node_##TYPE* current = deque->front; \
        while (current) { \
            print_fn(current->data); \
            if (current->next) printf(", "); \
            current = current->next; \
        } \
        printf("]\n"); \
    }

IMPLEMENT_DEQUE(int)
IMPLEMENT_DEQUE(char)
IMPLEMENT_DEQUE(float)
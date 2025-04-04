#include "circular_queue.h"
#include <stdio.h>

#define IMPLEMENT_CIRCULAR_QUEUE(TYPE) \
    Node_##TYPE* node_##TYPE##_create(TYPE data) { \
        Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
        new_node->data = data; \
        new_node->next = NULL; \
        return new_node; \
    } \
    Node_##TYPE* node_##TYPE##_destroy(Node_##TYPE* node) { \
        if (node) free(node); \
        return NULL; \
    } \
    CircularQueue_##TYPE* circular_queue_##TYPE##_create(void) { \
        CircularQueue_##TYPE* queue = malloc(sizeof(CircularQueue_##TYPE)); \
        if (!queue) return NULL; \
        queue->head = queue->tail = NULL; \
        queue->length = 0; \
        return queue; \
    } \
    void circular_queue_##TYPE##_destroy(CircularQueue_##TYPE* queue) { \
        if (!queue) return; \
        Node_##TYPE* current = queue->head; \
        while (current) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            free(temp); \
        } \
        free(queue); \
    } \
    bool circular_queue_##TYPE##_enqueue(CircularQueue_##TYPE* queue, TYPE data) { \
        if (!queue) return false; \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        if (queue->tail) { \
            queue->tail->next = new_node; \
            queue->tail = new_node; \
            queue->tail->next = queue->head; \
        } else { \
            queue->head = queue->tail = new_node; \
            queue->tail->next = queue->head; \
        } \
        queue->length++; \
        return true; \
    } \
    bool circular_queue_##TYPE##_dequeue(CircularQueue_##TYPE* queue, TYPE* out) { \
        if (!queue || queue->length == 0) return false; \
        *out = queue->head->data; \
        Node_##TYPE* temp = queue->head; \
        if (queue->head == queue->tail) { \
            queue->head = queue->tail = NULL; \
        } else { \
            queue->head = queue->head->next; \
            queue->tail->next = queue->head; \
        } \
        free(temp); \
        queue->length--; \
        return true; \
    } \
    size_t circular_queue_##TYPE##_length(const CircularQueue_##TYPE* queue) { \
        return queue ? queue->length : 0; \
    } \
    bool circular_queue_##TYPE##_is_empty(const CircularQueue_##TYPE* queue) { \
        return queue ? queue->length == 0 : true; \
    } \
    void circular_queue_##TYPE##_print(const CircularQueue_##TYPE* queue, void (*print_fn)(TYPE)) { \
        if (!queue || queue->length == 0) return; \
        printf("["); \
        Node_##TYPE* current = queue->head; \
        do { \
            print_fn(current->data); \
            if (current->next != queue->head) printf(", "); \
            current = current->next; \
        } while (current != queue->head); \
        printf("]\n"); \
    }

IMPLEMENT_CIRCULAR_QUEUE(int)
IMPLEMENT_CIRCULAR_QUEUE(char)
IMPLEMENT_CIRCULAR_QUEUE(float)

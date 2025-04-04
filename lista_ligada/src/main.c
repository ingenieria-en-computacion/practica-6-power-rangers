#include "linked_list.h"
#include <stdio.h>

void print_int(int value) {
    printf("%d", value);
}

void print_char(char value) {
    printf("%c", value);
}

int main() {
    List_int* nums = list_int_create();
    list_int_append(nums, 10);
    list_int_append(nums, 20);

    printf("Lista de enteros: ");
    list_int_print(nums, print_int); // imprime: [10, 20]

    list_int_destroy(nums);

    List_char *chars = list_char_create();
    list_char_append(chars, 'a');
    list_char_append(chars, 'b');
    list_char_append(chars, 'c');
    list_char_append(chars, 'd');
    list_char_append(chars, 'e');

    printf("Lista de caracteres: ");
    list_char_print(chars, print_char); // imprime: [a, b, c, d, e]

    list_char_destroy(chars);

    return 0;
}

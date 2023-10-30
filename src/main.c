#include<stdio.h>
#include<stdlib.h>

#include "data_structures/linked_list/llist.h"
#include "data_structures/stack/stack.h"

int main(int argc, char *argv[]) {
    LinkedList* list = llist_create(INT);
    int arr[3] = {1, 2, 3};
    llist_fromarr(list, &arr, 3);
    llist_print(list);
    llist_delete(list, &arr[1]);
    llist_print(list);
    llist_free(list);

    Stack* stack = stack_create(INT);
    stack_push(stack, &arr[0]);
    int* a = stack_peek(stack);
    stack_pop(stack);
    stack_push(stack, &arr[1]);
    int* b = stack_peek(stack);
    printf("%d\n%d\n", *a, *b);
    return 0;
}
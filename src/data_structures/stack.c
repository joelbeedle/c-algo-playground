// stack.c
#include<stdio.h>

#include "data_structures/stack.h"

Stack* stack_create(DataType type) {
    Stack* stack = malloc(sizeof(Stack));
    stack->list = llist_create(type);
    return stack;
}

void stack_push(Stack* stack, void* data) {
    Node* temp = createNode(stack->list->type, data, stack->list->dataSize);

    if (!temp) {
        fprintf(stderr, "Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }

    temp->next = stack->list->head;
    stack->list->head = temp;
}

void* stack_pop(Stack* stack) {
    Node* temp;

    if (stack->list->head == NULL) {
        fprintf(stderr, "Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }

    temp = stack->list->head;
    stack->list->head = stack->list->head->next;
    free(temp);
}

void* stack_peek(Stack* stack) {
    if (stack->list->head == NULL) {
        fprintf(stderr, "Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }

    return stack->list->head->data.data;
}
// stack.c
#include "data_structures/stack.h"

Stack *stack_create(DataType type) {
  Stack *stack = malloc(sizeof(Stack));
  stack->list = llist_create(type);
  return stack;
}

void stack_push(Stack *stack, void *data) {
  Node *temp = node_create(stack->list->type, data, stack->list->dataSize);

  if (!temp) {
    fprintf(stderr, "Error: stack overflow\n");
    exit(EXIT_FAILURE);
  }

  temp->next = stack->list->head;
  stack->list->head = temp;
}

// Pops the stack and returns the value of the popped node
void *stack_pop(Stack *stack) {
  Node *temp;

  if (stack->list->head == NULL) {
    fprintf(stderr, "Error: stack underflow\n");
    exit(EXIT_FAILURE);
  }

  temp = stack->list->head;
  stack->list->head = stack->list->head->next;
  return temp->data.data;
  free(temp);
}

// Returns the value of the element at the top of teh stack
void *stack_peek(Stack *stack) {
  if (stack->list->head == NULL) {
    fprintf(stderr, "Error: stack underflow\n");
    exit(EXIT_FAILURE);
  }

  return stack->list->head->data.data;
}

#ifndef STACK_H
#define STACK_H

#include "data_structures/linkedlist.h"
#include "utils/data_types.h"

typedef struct Stack Stack;

struct Stack {
  LinkedList *list;
};

Stack *stack_create(DataType type);
void stack_push(Stack *stack, void *data);
void *stack_pop(Stack *stack);
void *stack_peek(Stack *stack);

#endif // STACK_H